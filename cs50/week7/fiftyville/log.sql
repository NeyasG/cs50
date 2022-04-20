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
-- Emma: Sucpicious person came in whispering into phone for 30 minutes. Didn't buy anything.

-- Querying for Security Footage from bakery on July 28th at 10:15am.
-- License plates of all cars leaving bakery within timeframe
SELECT activity, license_plate FROM bakery_security_logs WHERE
year = 2021
AND month = 7
AND day = 28
AND hour = 10
AND minute BETWEEN 15 AND 25;

-- Querying for Leggett Street ATM transactions in the morning hour <= 12
SELECT people.name, atm_transactions.account_number, bank_accounts.person_id, transaction_type, amount
FROM atm_transactions
-- Joining This information with bank_accounts and peeoples tables to identify names
INNER JOIN bank_accounts ON atm_transactions.account_number = bank_accounts.account_number
INNER JOIN people ON bank_accounts.person_id = people.id
WHERE
year = 2021
AND month = 7
AND day = 28
AND atm_location = "Leggett Street"
AND transaction_type = "withdraw";

-- Following second lead, Querying phone calls around time of Theft.
SELECT duration, people.name, caller FROM phone_calls
INNER JOIN people ON phone_calls.caller = people.phone_number
WHERE year = 2021
AND month = 7
AND day = 28
AND duration < 60;

    SELECT duration, people.name, receiver FROM phone_calls
    INNER JOIN people ON phone_calls.receiver = people.phone_number
    WHERE year = 2021
    AND month = 7
    AND day = 28
    AND duration < 60;
