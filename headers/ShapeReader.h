#ifndef FIGURES_SHAPEREADER_H
#define FIGURES_SHAPEREADER_H

#include "Rectangle.h"
#include "Triangle.h"
#include "Circle.h"
#include "Shape.h"
#include <memory>
#include <iostream>
#include <map>

class CShapeReader
{
public:
    CShapeReader(std::vector<std::shared_ptr<CShape>>& shapes, std::istream& input, std::ostream& output);
    bool HandleInput();

    //std::vector<std::shared_ptr<ISolidShape>>& GetShapes() const;
    std::vector<std::shared_ptr<CShape>>& GetShapes() const;

    CShapeReader& operator=(const CShapeReader&) = delete;
private:
    //std::vector<std::shared_ptr<ISolidShape>>& m_shapes;
    std::vector<std::shared_ptr<CShape>>& m_shapes;
    std::istream& m_input;
    std::ostream& m_output;

    using Handler = std::function<bool(std::istream& args)>;
    using ActionMap = std::map<std::string, Handler>;

    const ActionMap m_actionMap;

    bool AddRect(std::istream& inpStrm);
    bool AddTriangle(std::istream& inpStrm);
    bool AddCircle(std::istream& inpStrm);
};

#endif //FIGURES_SHAPEREADER_H
