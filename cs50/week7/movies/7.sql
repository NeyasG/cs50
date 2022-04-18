SELECT title
FROM movies WHERE year = 2010
INNER JOIN ratings
ON ratings.movie_id = movies.id;