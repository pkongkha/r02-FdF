_This project has been created as part of the 42 curriculum by pkongkha_

# Description
The project aims to provide know-how about 3D projection. Especially about _isometric_ projection.

## Implementation
First, locate the point projected on (x, y) by first apply scailing, then rotate the point, in this way, the projection would be percise.

Second, draw a line connected point nearby, applying color gradient while drawing a line.

## Calculation
To project the isometric projection, use hrot = arctan(1/sqrt(2)) deg, and vrot = 45deg
- $P_x = x(cos(vrot)) + z(-sin(vrot))$
- $P_y = x(-sin(hrot))(sin(vrot)) + y(cos(hrot)) + z(-sin(hrot))(cos(vrot))$
- $P_z = x(cos(hrot))(sin(vrot)) + y(sin(hrot)) + z(cos(hrot))(cos(vrot))$
But we won't use P_z as our screen is only 2d

# Instructions

To build the project
```sh
make all
```

And to run
```sh
./fdf <maps_to_project>
```

# Resources
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
