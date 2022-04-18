SELECT title FROM movies
WHERE id IN
(
    SELECT movie_id FROM stars
    WHERE person_id IN
    (
        SELECT id IN people
        WHERE name IN ("Johnny Depp", "Helena Bonham Carter")
    )
);