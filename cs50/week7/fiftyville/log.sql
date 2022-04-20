-- Keep a log of any SQL queries you execute as you solve the mystery.

-- Theft took place on July 28th 2021 on Humphrey Street
-- Querying crime_scene_reports for details
SELECT id, description FROM crime_scene_reports WHERE street = "Humphrey Street"
AND year = 2021
AND month = 7
AND day = 28;

-- Description of crime: Theft of the CS50 duck took place at 10:15am at the Humphrey Street bakery.
-- Interviews were conducted today with three witnesses who were present at the time – each of their interview transcripts mentions the bakery.

-- Querying for interviews on specific date containing the word "bakery"
SELECT name, transcript FROM interviews WHERE transcript LIKE "%bakery%"
AND year = 2021
AND month = 7
AND day = 28;

-- Notes from interviews
-- Ruth: Within 10 minutes of theft (10:15am) car left bakery parking lot. Check Security footage from bakery
-- Eugene: Recognised Thief. Saw thief withdrawing money from ATM on Leggett Street in the morning
-- Raymond: Phone call to thief after leaving bakery. Planning to take earliest flight out of fiftyville on 29th July. Asked caller to purchase ticket
-- Emma: Suspicious person came in whispering into phone for 30 minutes. Didn't buy anything.

-- Querying for Security Footage from bakery on July 28th at 10:15am.
-- License plates of all cars leaving bakery within timeframe joined to people table to identify possible suspects
DROP VIEW IF EXISTS security_logs;
CREATE VIEW security_logs AS
SELECT activity, name, bakery_security_logs.license_plate
FROM bakery_security_logs
INNER JOIN people ON bakery_security_logs.license_plate = people.license_plate
WHERE year = 2021
AND month = 7
AND day = 28
AND hour = 10
AND minute BETWEEN 15 AND 25;
SELECT * FROM security_logs;

-- Querying for Leggett Street ATM transactions in the morning hour <= 12
-- Joining This information with bank_accounts and peeoples tables to identify names
DROP VIEW IF EXISTS atm_logs;
CREATE VIEW atm_logs AS
SELECT people.name, atm_transactions.account_number, bank_accounts.person_id, transaction_type, amount
FROM atm_transactions
INNER JOIN bank_accounts ON atm_transactions.account_number = bank_accounts.account_number
INNER JOIN people ON bank_accounts.person_id = people.id
WHERE year = 2021
AND month = 7
AND day = 28
AND atm_location = "Leggett Street"
AND transaction_type = "withdraw";
SELECT * FROM atm_logs;

-- Following second lead, Querying phone calls around time of Theft.
-- Creating view for caller table
DROP VIEW IF EXISTS caller_names;
CREATE VIEW caller_names AS
SELECT duration, people.name, caller FROM phone_calls
INNER JOIN people ON phone_calls.caller = people.phone_number
WHERE year = 2021
AND month = 7
AND day = 28
AND duration < 60;

-- Creating View for receiver table
DROP VIEW IF EXISTS receiver_names;
CREATE VIEW receiver_names AS
SELECT duration, people.name, receiver FROM phone_calls
INNER JOIN people ON phone_calls.receiver = people.phone_number
WHERE year = 2021
AND month = 7
AND day = 28
AND duration < 60;

-- Joining caller and receiver table together to visualise all phone calls around time of theft.
DROP VIEW IF EXISTS phone_logs;
CREATE VIEW phone_logs AS
SELECT caller_names.duration, caller_names.name, caller, receiver_names.name, receiver
FROM caller_names
INNER JOIN receiver_names ON caller_names.duration = receiver_names.duration;
SELECT * FROM phone_logs;

-- Using the security logs, ATM transactions and the phone call table we can narrow down suspects.
SELECT *
FROM (( security_logs
    INNER JOIN atm_logs ON security_logs.name = atm_logs.name
    INNER JOIN phone_logs ON security_logs.name = phone_logs.name
));

-- Suspects remaining are Bruce, accomplice Robin, or Diana, accomplice Philip.
-- Will use flight ticket purchase to identify who it could be.
SELECT * FROM flights
INNER JOIN
WHERE origin_airport_id IN
(
    SELECT id FROM airports WHERE city = "Fiftyville"
)
AND year = 2021
AND month = 7
AND day = 29
ORDER BY hour ASC
LIMIT 1;
