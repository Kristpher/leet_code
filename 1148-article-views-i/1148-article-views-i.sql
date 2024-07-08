# Write your MySQL query statement below
SELECT distinct viewer_id as id
FROM Views
WHERE author_id=viewer_id
order by viewer_id