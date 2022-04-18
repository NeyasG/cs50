SELECT title FROM movies WHERE year = 2010
JOIN ratings
ON ratings.movie_id = movies.id;