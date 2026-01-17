# Learning Resource

# Procedure
1. To do it, first we need to locate each point on x,y projection
    1.1 You can achieve this by using scailing
    1.2 Then you rotate the projected point
        1.2.1 arctan(1/sqrt(2)) deg horizonally
        1.2.2 45 deg vertically
2. Draw a line
    2.1 Draw line from each point to another point
    2.2 Apply color gradient
3. For more accuracy
    3.1 render the backmost line first when doing rotation
        3.1.1 I do not personally implemented this, anyone who interested in can try


# Calculation
$P_x = x(cos(vrot)) + z(-sin(vrot))$
$P_y = x(-sin(hrot))(sin(vrot)) + y(cos(hrot)) + z(-sin(hrot))(cos(vrot))$
$P_z = x(cos(hrot))(sin(vrot)) + y(sin(hrot)) + z(cos(hrot))(cos(vrot))$
But we won't use P_z as our screen is only 2d

# References
- [Harm Smits | 42docs minilibx introduction](http://harm-smits.github.io/42docs/libs/minilibx/introduction.html)
- [Minilibx-linux manual pages](man:mlx(3))
- [Minilibx-linux source code](https://github.com/42paris/minilibx-linux)
- [WikiPedia | Color depth](https://en.wikipedia.org/wiki/Color_depth)
- [WikiPedia | Isometric projection](https://en.wikipedia.org/wiki/Isometric_projection)
- [WikiPedia | Rotation matrix](https://en.wikipedia.org/wiki/Rotation_matrix)
- [WikiPedia | Bresenham's line algorithm](https://en.wikipedia.org/wiki/Bresenham%27s_line_algorithm)
- [WikiPedia | Aircraft principle axes](https://en.wikipedia.org/wiki/Aircraft_principal_axes)
- [WikiPedia | 3D Projection](https://en.wikipedia.org/wiki/3D_projection)
- [WikiPedia | Cartesian coordinate system](https://en.wikipedia.org/wiki/Cartesian_coordinate_system)
## Optimization
- [Line Clipping | Set 1 (Cohen–Sutherland Algorithm)](https://www.geeksforgeeks.org/dsa/line-clipping-set-1-cohen-sutherland-algorithm/)