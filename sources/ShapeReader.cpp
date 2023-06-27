#include "../headers/ShapeReader.h"
#include <iomanip>
#include <sstream>

using namespace std;
CShapeReader::CShapeReader(vector<shared_ptr<CShape>>& shapes, istream &input, ostream &output)
        :m_shapes(shapes), m_input(input), m_output(output),
        m_actionMap({
            {"rectangle", [this](istream& strm) {
                return AddRect(strm);
            }},
            {"triangle", [this](istream& strm) {
                return AddTriangle(strm);
            }},
            {"circle", [this](istream& strm) {
                return AddCircle(strm);
            }}
        })
{
}

bool CShapeReader::HandleInput()
{
    string commandLine;
    getline(m_input, commandLine);
    istringstream strm(commandLine);

    string action;
    strm >> action;
    auto it = m_actionMap.find(action);
    if (it != m_actionMap.end())
    {
        return it->second(strm);
    }
    return false;
}

bool CShapeReader::AddRect(istream &inpStrm)
{
    double x, y, width, height;
    uint32_t outlineColor, fillColor;
    inpStrm >> x >> y >> width >> height >> outlineColor >> fillColor;
    if (!inpStrm.eof())
    {
        m_output << "Too many args" << endl;
        return true;
    }
    if (inpStrm.fail())
    {
        m_output << "Too few args" << endl;
        return true;
    }
    m_shapes.push_back(shared_ptr<CRectangle>(
            new CRectangle({x, y}, width, height, outlineColor, fillColor)
            ));
    return true;
}

bool CShapeReader::AddTriangle(istream &inpStrm)
{
    double x1, x2, x3, y1, y2, y3;
    uint32_t outlineColor, fillColor;
    inpStrm >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> outlineColor >> fillColor;
    if (!inpStrm.eof())
    {
        m_output << "Too many args" << endl;
        return true;
    }
    if (inpStrm.fail())
    {
        m_output << "Too few args" << endl;
        return true;
    }
    m_shapes.push_back(shared_ptr<CTriangle>(
            new CTriangle({x1, y1}, {x2, y2}, {x3, y3}, outlineColor, fillColor)
            ));
    return true;
}

bool CShapeReader::AddCircle(istream &inpStrm)
{
    double x, y, radius;
    uint32_t outlineColor, fillColor;
    inpStrm >> x >> y >> radius >> outlineColor >> fillColor;
    if (!inpStrm.eof())
    {
        m_output << "Too many args rest: " << endl;
        return true;
    }
    if (inpStrm.fail())
    {
        m_output << "Too few args" << endl;
        return true;
    }
    m_shapes.push_back(shared_ptr<CCircle>(
            new CCircle({x, y}, radius, outlineColor, fillColor)
            ));
    return true;
}

std::vector<std::shared_ptr<CShape>> &CShapeReader::GetShapes() const
{
    return m_shapes;
}



