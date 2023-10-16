//<0: clockwise, >0: counter-clockwise, 0: collinear
//x: first, y: second
int ccw (Point P0, Point P1, Point P2) {
    return (P1.x - P0.x)*(P2.y - P0.y) - (P1.y - P0.y)*(P2.x - P0.x);
}

//start: first, end: second
//kiem tra 2 doan thang cat nhau
bool intersect (Vector2D v1, Vector2D v2) {
    if ((((ccw(v1.start, v1.end, v2.start) *
    ccw(v1.start, v1.end, v2.end)) == 0) &&
    ((ccw(v2.start, v2.end, v1.start) *
    ccw(v2.start, v2.end, v1.end)) == 0)))
        return 0;

    return (((ccw(v1.start, v1.end, v2.start) *
    ccw(v1.start, v1.end, v2.end)) <= 0) &&
    ((ccw(v2.start, v2.end, v1.start) *
    ccw(v2.start, v2.end, v1.end)) <= 0));
}
