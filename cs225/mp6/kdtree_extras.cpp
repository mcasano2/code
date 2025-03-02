#include <unistd.h>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>

#include "coloredout.h"

const int32_t _KDTree_maxPrintLen = 79;

template <typename T>
inline std::string to_string(const T & value)
{
    std::ostringstream ss;
    ss << value;
    return ss.str();
}

// old operator<< 
// prints a tree without intelligence. used for grading only.
template<int Dim>
std::ostream & operator<<(std::ostream & out, KDTree<Dim> const & tree)
{
    tree.gradingPrint(out);
    return out;
}


template<int Dim>
void KDTree<Dim>::gradingPrint(std::ostream & out) const
{
    for (unsigned int i = 0; i < points.size(); ++i)
    {
        out << "Point #"<< i << " coords = (";
        for (unsigned int j = 0; j < Dim; ++j)
        {
            if (j > 0)
                out << ", ";
            out << points[i][j];
        }
        out << ") index = " << point_index[i] << std::endl;
    }
}


template <int Dim>
void KDTree<Dim>::printVectors(ostream & out /* = cout */, colored_out::enable_t enable_bold /* = COUT */) const
{
    std::ostringstream headers;
    std::ostringstream * points_lines = new std::ostringstream[points.size()];

    // output points[]
    headers << "points[]:";
    ssize_t max_len = headers.tellp();
    for (size_t i = 0; i < points.size(); i++)
    {
        points_lines[i] << "p["<< i << "] = " << points[i];
        if (points_lines[i].tellp() > max_len)
            max_len = points_lines[i].tellp();
    }
    while (headers.tellp() < max_len)
        headers << ' ';
    for (size_t i = 0; i < points.size(); i++)
        while (points_lines[i].tellp() < max_len)
            points_lines[i] << ' ';

    // output point_index[]
    headers << "    point_index[]:";
    max_len = headers.tellp();
    for (size_t i = 0; i < point_index.size(); i++)
    {
        points_lines[i] << "    p_i["<< i << "] = " << point_index[i];
        if (points_lines[i].tellp() > max_len)
            max_len = points_lines[i].tellp();
    }
    while (headers.tellp() < max_len)
        headers << ' ';
    for (size_t i = 0; i < points.size(); i++)
        while (points_lines[i].tellp() < max_len)
            points_lines[i] << ' ';

    // output points[point_index[]]
    headers << "    points[point_index[]]:";
    max_len = headers.tellp();
    for (size_t i = 0; i < point_index.size(); i++)
    {
        points_lines[i] << "    p[p_i["<< i << "]] = ";
        if (point_index[i] < 0 || (size_t)point_index[i] >= points.size())
            points_lines[i] << "out of bounds";
        else
            points_lines[i] << points[point_index[i]];
        if (points_lines[i].tellp() > max_len)
            max_len = points_lines[i].tellp();
    }
    while (headers.tellp() < max_len)
        headers << ' ';
    for (size_t i = 0; i < points.size(); i++)
        while (points_lines[i].tellp() < max_len)
            points_lines[i] << ' ';

    // output lines
    colored_out::output_bold(headers.str(), out, enable_bold);
    out << endl;
    for (size_t i = 0; i < points.size(); i++)
        out << points_lines[i].str() << endl;

    delete [] points_lines;
}

template <int Dim>
void KDTree<Dim>::printTree(ostream & out /* = cout */,
                            colored_out::enable_t enable_bold /* = COUT */,
                            int modWidth /* = -1*/) const
{
    // Base case
    if (points.size() == 0)
    {
        out << "(empty)" << endl;
        return;
    }

    // Make a character matrix for outputting the tree onto
    int rootData = getPrintData(0, points.size()-1);
    int height   = (Dim+1) * rootData + Dim;
    int width;
    if (modWidth != -1)
        width    = (4 << modWidth) - 3;
    else
        width    = (4 << rootData) - 3;
    
    if (width + 6 > _KDTree_maxPrintLen)
    {
        out << "(tree too large for terminal)" << endl;
        return;
    }

    // Initialize this matrix to be filled with spaces
    vector<string> output(height);
    for (size_t i = 0; i < output.size(); i++)
        output[i] = string(width+6, ' '); // extra room for long things

    // Recursively print each node
    printTree(0, points.size()-1, output, 0, 0, width, 0);
    //nodeOut << std::unsetf(
    // Output the matrix
    int currd = 0;
    for (int row = 0; row < height; )
    {
        for (int d = 0; d < Dim+1 && row < height; d++, row++)
        {
            if (d == currd)
                colored_out::output_bold_digits(output[row], out, enable_bold);
            else
                out << output[row];
            out << endl;
        }
        currd = (currd + 1) % Dim;
    }
}

// Finds height of each node to determine the size of the output matrix
template <int Dim>
int KDTree<Dim>::getPrintData(int low, int high) const
{
    using std::max;
    if (low > high) return -1;
    return 1 + max( getPrintData(low, (low+high)/2 - 1),
                    getPrintData((low+high)/2 + 1, high) );
}

// Recursively prints tree to output matrix
template <int Dim>
void KDTree<Dim>::printTree(int low, int high, vector<string> & output,
                            int left, int top, int width, int currd) const
{
    // Convert data to string
    int med = (low+high)/2;
    vector<string> nodeStr;
    nodeStr.reserve(Dim);
    for (int dim = 0; dim < Dim; dim++)
    {
        std::ostringstream nodeOut;
        nodeOut << std::fixed << std::setprecision(0);
        
        Point<Dim> p = points[point_index[med]];
        if (dim == 0)
            nodeOut << (p.is_mine() ? '{' : '(');
        else
            nodeOut << ' ';
    
        nodeOut << p[dim];
        if (dim == Dim - 1)
            nodeOut << (p.is_mine() ? '}' : ')');
        else
            nodeOut << ',';
        
        nodeStr.push_back(nodeOut.str());
    }
    
    // Output data
    for (int dim = 0; dim < Dim; dim++)
        for (size_t i = 0;
             i < nodeStr[dim].length() && (left + width/2 + i < output[top+dim].length());
             i++)
            output[top+dim][left + width/2 + i] = nodeStr[dim][i];
    
    // Calculate / \ offset = 2 ^ height
    int branchOffset = (width+3) >> 3; //(1 << (node->printData - 1));
    
    // Print left child
    int center = left + width/2;
    int leftcenter = left + (width/2 - 1)/2;
    int rightcenter = left + width/2 + 2 + (width/2 - 1)/2;
    if (low != med) //node->left  != NULL
    {
        int branch_pos = center - branchOffset + 1;
        // draw left upper branch
        for (int pos = center - 1; pos > branch_pos; pos--)
            output[top+Dim-1][pos] = '_';
        // draw left '/'
        output[top+Dim][branch_pos] = '/';
        // draw left lower branch
        for (int pos = branch_pos-1; pos > leftcenter + 2; pos--)
            output[top+Dim][pos] = '_';
        // draw left subtree
        printTree(low, med-1, output, left, top+Dim+1, width/2 - 1, (currd+1) % Dim);
    }
    // Print right child
    if (high != med) //node->right != NULL
    {
        int branch_pos = center + branchOffset + 1;
        // draw right upper branch
        for (int pos = center + nodeStr[Dim-1].length(); pos < branch_pos; pos++)
            output[top+Dim-1][pos] = '_';
        // draw right '\'
        output[top+Dim][branch_pos] = '\\';
        // draw right lower branch
        for (int pos = branch_pos+1; pos < rightcenter; pos++)
            output[top+Dim][pos] = '_';
        // draw right subtree
        printTree(med+1, high, output, left + width/2 + 2, top+Dim+1, width/2 - 1, (currd+1) % Dim);
    }
}

