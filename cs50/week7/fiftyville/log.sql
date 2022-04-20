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
-- Eugene: Recognised Thief. Saw thief withdrawing money from ATM on Legget Street in the morning
-- Raymond: Phone call to thief after leaving bakery. Planning to take earliest flight out of fiftyville on 29th July. Asked caller to purchase ticket
-- Emma: Sucpicious person came in whispering into phone for 30 minutes. Didn't buy anything.

-- Querying for Security Footage from bakery on July 28th at 10:15am.
SELECT activity, license_plate FROM bakery_security_logs WHERE
year = 2021
AND month = 7
AND day = 28
AND hour = 10
AND minute = 15;
