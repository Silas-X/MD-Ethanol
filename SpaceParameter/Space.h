#ifndef SPACE_H
#define SPACE_H
#include <math.h>

namespace space
{
struct Location
{
    double x, y, z;
    Location(double _x, double _y, double _z)
    {
        x = _x;
        y = _y;
        z = _z;
    }
    Location(const Location &origin)
    {
        this->x = origin.x;
        this->y = origin.y;
        this->z = origin.z;
    }

    Location GetLocation() const { return *this; }
    double GetLength() const
    {
        return (sqrt(x * x + y * y + z * z));
    }
    double GetDistance(const Location &another) const
    {
        double dx = x - another.x;
        double dy = y - another.y;
        double dz = z - another.z;
        return (sqrt(dx * dx + dy * dy + dz * dz));
    }

    Location GetDifference(const Location &another) const
    {
        double dx = x - another.x;
        double dy = y - another.y;
        double dz = z - another.z;
        return (Location{dx, dy, dz});
    }
};

struct
{
    double x, y, z;
} dir[6] = {{0, 0, 1}, {0, 1, 0}, {0, 0, -1}, {0, -1, 0}, {1, 0, 0}, {-1, 0, 0}};//up[001],right[010],down[00-1],left[0-10] .[100] x[-100]

} // namespace space
#endif SPACE_H