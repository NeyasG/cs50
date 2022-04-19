-- Keep a log of any SQL queries you execute as you solve the mystery.

-- Theft took place on July 28th 2021 on Humphrey Street
-- Querying crime_scene_reports for details
SELECT description FROM crime_scene_reports WHERE street = "Humphrey Street"
AND year = 2021
AND month = 7
AND day = 28;

-- Description of crime