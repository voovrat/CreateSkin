A 3d Euclidean point cloud aligned in main axis directions (x, y, z) and with a constant distance grid starting at a given reference point (the point with indices 0, 0, 0 is located at reference point) is intersected by a move of sphere,
 where the path of the sphere center is defined by a user given formula $x = f (t)$ where $t$ is in the interval between $t_0$ and $t_1$ . 
 
 The function $f(t)$ can
be handled as a discrete function with a user given $\Delta t$.
 Points that intersect with the sphere move are considered as deleted.


 Only the first layer of points (which remains visible/undeleted) from top view must be written
to a file as ASCII data (the skin of the point cloud from top view). The file
format is defined as follows:

\begin{itemize}
  \item Each line contains a single point.
  \item The point definition contains x, y and z coordinates delimited by space characters.
  \item Each line ends with a new line character.
\end{itemize}


