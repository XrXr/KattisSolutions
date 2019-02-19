#include <iostream>
#include <cmath>
#include <vector>


struct point {
    double x, y;
};

void normalize(point &p) {
    double length = hypot(p.x, p.y);
    p.x = p.x / length;
    p.y = p.y / length;
};

using namespace std;
int main() {
    int n;
    cin >> n;

    vector<point> points;
    for (int i = 0; i < n; i++) {
        double x, y;
        cin >> x >> y;
        points.push_back(point{x, y});
    }

    double answer = 0x3f3f3f3f;

    for (int i = 0; i < n; i++) {
        point p0 = points[i];
        point p1;
        if (i == n - 1) {
            p1 = points[0];
        } else {
            p1 = points[i+1];
        }
        point vec{ p1.x - p0.x, p1.y - p0.y };
        normalize(vec);
        point ortho{ -1.0 * vec.y/vec.x, 1.0 };
        normalize(ortho);
        if (vec.x == 0) {
            ortho = point{1, 0};
        } else if (vec.y == 0) {
            ortho = point{0, 1};
        }

        vector<point> rotated(points);
        double a = ortho.x;
        double b = vec.x;
        double c = ortho.y;
        double d = vec.y;
        double det = double(1) / double(a*d - b*c);
        point xBasis{ det * d, det * -c };
        point yBasis{ det * -b, det * a };


        for (auto &p : rotated) {
            p = point{xBasis.x * p.x + yBasis.x * p.y, xBasis.y * p.x + yBasis.y * p.y};
        }

        double reference = rotated[i].x;
        double maxXDist = 0; 
        for (const auto &p : rotated) {
            double dist = p.x - reference;
            dist = fabs(dist);
            if (dist > maxXDist) {
                maxXDist = dist;
            }
        }
        if (maxXDist < answer) {
            answer = maxXDist;
        }
    }
    cout << answer << endl;
}

