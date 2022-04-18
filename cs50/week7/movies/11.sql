SELECT movies.title ratings.rating
FROM movies
INNER JOIN ratings ON ratings.movie_id = movie.id
WHERE id IN(
    1
);