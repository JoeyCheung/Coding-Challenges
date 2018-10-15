
-- Query the list of CITY names from STATION that do not start with vowels. Your result cannot contain duplicates --
SELECT DISTINCT CITY
FROM STATION 
WHERE substr(CITY,1,1) NOT IN ('A','E','I','O','U');

-- Query all columns for all American cities in CITY with populations larger than 100000. The CountryCode for America is USA  --
SELECT * FROM City 
WHERE Countrycode='USA' and Population>100000;

-- Query all columns (attributes) for every row in the CITY table --
SELECT * FROM CITY;

-- Query all columns for a city in CITY with the ID 1661 --
SELECT * FROM CITY
WHERE ID = 1661;

-- Query the names of all the Japanese cities in the CITY table. The COUNTRYCODE for Japan is JPN --
SELECT NAME FROM CITY
WHERE COUNTRYCODE = 'JPN'; 

-- Query the names of all American cities in CITY with populations larger than 120000. The CountryCode for America is USA --
SELECT NAME FROM CITY
WHERE COUNTRYCODE = 'USA' AND POPULATION > 120000;

-- Query all attributes of every Japanese city in the CITY table. The COUNTRYCODE for Japan is JPN --
SELECT * FROM CITY
WHERE COUNTRYCODE = 'JPN';

-- Query a list of CITY and STATE from the STATION table --
SELECT CITY, STATE
FROM STATION

-- Query a list of CITY names from STATION with even ID numbers only. You may print the results in any order, but must exclude duplicates from your answer --
SELECT DISTINCT CITY 
FROM STATION 
WHERE MOD(STATION.ID,2)=0;

-- Let be the number of CITY entries in STATION, and let be the number of distinct CITY names in STATION; query the value of from STATION. In other words, find the difference between the total number of CITY entries in the table and the number of distinct CITY entries in the table --
SELECT COUNT(CITY) - COUNT(DISTINCT CITY)
FROM STATION;

-- Query the two cities in STATION with the shortest and longest CITY names, as well as their respective lengths (i.e.: number of characters in the name). If there is more than one smallest or largest city, choose the one that comes first when ordered alphabetically --
SELECT CITY, LENGTH(CITY)
FROM (SELECT CITY
      FROM STATION
     ORDER BY LENGTH(CITY), CITY)
WHERE ROWNUM = 1;

-- Query the list of CITY names starting with vowels (i.e., a, e, i, o, or u) from STATION. Your result cannot contain duplicates --
SELECT DISTINCT(CITY) 
FROM STATION 
WHERE CITY LIKE 'A%' OR CITY LIKE 'E%' OR CITY LIKE 'I%' OR CITY LIKE 'O%' OR CITY LIKE 'U%';  
