SELECT movies.title, ratings.rating
FROM movies
INNER JOIN ratings ON ratings.movie_id = movies.id
WHERE id IN(
    
);