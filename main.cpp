#include "ShapeReader.h"

using namespace std;

shared_ptr<CShape> MinPerimeterShape(const vector<shared_ptr<CShape>>& shapes)
{
    if (shapes.empty())
    {
        return nullptr;
    }
    auto minPerimeterShape = shapes[0];
    for (auto& shape: shapes)
    {
        if (shape->GetPerimeter() < minPerimeterShape->GetPerimeter())
        {
            minPerimeterShape = shape;
        }
    }
    return minPerimeterShape;
}
//TODO: использоваться стандартный алгоритм
shared_ptr<CShape> MaxAreaShape(const vector<shared_ptr<CShape>>& shapes)
{
    if (shapes.empty())
    {
        return nullptr;
    }
    auto maxAreaShape = shapes[0];
    for (auto& shape: shapes)
    {
        if (shape->GetArea() > maxAreaShape->GetArea())
        {
            maxAreaShape = shape;
        }
    }
    return maxAreaShape;
}
//TODO: использовать паттерн "шаблонный метод"
// избавиться от дублирования в ToString()
int main()
{
    vector<shared_ptr<CShape>> shapes;
    CShapeReader reader(shapes, cin, cout);
    while (!cin.eof())
    {
        cout << ">";
        if (!reader.HandleInput())
        {
            cout << "Unknown command" << endl;
        }
    }
    auto maxArea = MaxAreaShape(shapes);
    if (!maxArea)
    {
        cout << "Empty list" << endl;
        return 0;
    }
    cout << endl << "Max area: " << endl;
    cout << maxArea->ToString() << endl;
    auto minPerimeter = MinPerimeterShape(shapes);
    cout << "Min perimeter:" << endl;
    cout << minPerimeter->ToString() << endl;
    return 0;
}