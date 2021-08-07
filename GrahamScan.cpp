#define PI 3.14159265
struct position {
	int id;
	int x;
	int y;
};
double angle(position pivot, position point) {
	double x = atan2(point.y - pivot.y, point.x - pivot.x);
	if (x < 0) x += PI + PI;
	return x;
}
bool belokkiri(position a, position b, position c) {
	double gab = angle(a, b);
	double gac = angle(a, c);
	return gab <= gac;
}
double dist(position a, position b) {
	int dx = b.x - a.x;
	int dy = b.y - a.y;
	return sqrt(dx * dx + dy * dy);
}
position pivot;
bool anglecmp(position a, position b) {
	double anglea = angle(pivot, a);
	double angleb = angle(pivot, b);
	if (anglea == angleb) {
		return dist(pivot, a) < dist(pivot, b);
	} else {
		return anglea < angleb;
	}
}

//dalam int main()
for (int i = 1; i < n; i++) 
{
if (pos[i].y < pos[mnpos].y || (pos[i].y == pos[mnpos].y && pos[i].x > pos[mnpos].x)) 
{
		mnpos = i;
}			}
if (pos[i].y < pos[botleft].y || (pos[i].y == pos[botleft].y && pos[i].x < pos[botleft].x)) 
{
		botleft = i;
	}
}
position tmp = pos[0];
pos[0] = pos[mnpos];
pos[mnpos] = tmp;
pivot = pos[0];
sort(pos+1, pos+n, anglecmp);
vector<position> hull;
hull.push_back(pos[n-1]);
hull.push_back(pos[0]);
hull.push_back(pos[1]);
int z = 2;
while (z < n) 
{
int i = z % n;
int j = hull.size()-1;
if (angle(hull[j-1], hull[j]) == angle(hull[j-1], pos[i]) && dist(hull[j-1], hull[j]) == dist(hull[j-1], pos[i])) 
{
		z++;
		continue;
	}
	if (belokkiri(hull[j-1], hull[j], pos[i])) 
{
if (angle(hull[j-1], hull[j]) == angle(hull[j-1], pos[i]))
	hull.pop_back();
		hull.push_back(pos[i]);
		z++;
	} 
else
{
		hull.pop_back();
	}
}
