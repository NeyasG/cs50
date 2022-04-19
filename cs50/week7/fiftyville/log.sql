-- Keep a log of any SQL queries you execute as you solve the mystery.

-- Theft took place on July 28th 2021 on Humphrey Street
-- Querying crime_scene_reports for details
SELECT id, description FROM crime_scene_reports WHERE street = "Humphrey Street"
AND year = 2021
AND month = 7
AND day = 28;

-- Description of crime: Theft of the CS50 duck took place at 10:15am at the Humphrey Street bakery.
-- Interviews were conducted today with three witnesses who were present at the time – each of their interview transcripts mentions the bakery.

SELECT name, transcript FROM interviews WHERE year = 2021
AND month = 7
AND day = 28
AND ;
