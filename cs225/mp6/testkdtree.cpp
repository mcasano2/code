#include <sstream>

#include "coloredout.h"
#include "kdtree.h"
#include "point.h"


// Global helper data and functions

bool is_terminal = false;
bool is_colored  = false;
colored_out::enable_t color_scheme = colored_out::DISABLE;

void output_header(string name, string desc)
{
    const string bar(79, '~');
    cout << bar << endl;
    colored_out::output_bold(name, cout, color_scheme);
    cout << " - " << desc << endl;
    cout << bar << endl;
}


/******************************************************************************
 * Test Cases
 *****************************************************************************/

/**
 * Test the KDTree constructor
 */
template <int K>
void testLinearCtor(int size)
{
    output_header("testLinearCtor<"+to_string(K)+">(" + to_string(size) + ")",
                  "constructs a " + to_string(K) +
                  "D tree of points 0 through " + to_string(size-1));

    vector< Point<K> > points;
    points.reserve(size);
    for (int i = 0; i < size; i++)
    {
        Point<K> p;
        for (int j = 0; j < K; j++)
            p[j] = i;
        points.push_back(p);
    }

    KDTree<K> tree(points);


    tree.printVectors();
    cout << endl << "~  ";
    colored_out::output_bold("Tree Diagram", cout, color_scheme);
    cout << "  ~    ~    ~    ~    ~    ~    ~";
    cout << endl;
    tree.printTree(cout, color_scheme);
    cout << endl;
}


/**
 * Test the KDTree Nearest Neighbor Search
 */
template <int K>
void testLinearNNS(int size)
{
    output_header("testLinearNNS<"+to_string(K)+">(" + to_string(size) + ")",
                  "findNearestNeighbor on a " + to_string(K) +
                  "D tree of elements 0 to " + to_string(size-1));

    vector< Point<K> > points;
    points.reserve(size);
    for (int i = 0; i < size; i++)
    {
        Point<K> p;
        for (int j = 0; j < K; j++)
            p[j] = i;
        points.push_back(p);
    }
    
    KDTree<K> tree(points);

    for (size_t i = 0; i < points.size(); i++)
    {
        cout << "findNearestNeighbor(" << points[i] << ") = ";
        cout << tree.findNearestNeighbor(points[i]) << endl;
    }

    cout << endl;
}



/*****************************************
*                    8                   * 
*     X              7     X             * 
*                    6                   * 
*                    5                   * 
*                    4                   * 
*                    3                   * 
*                    2             X     * 
*       O            1                   * 
* 9876543210987 X 32101234567890123456789* 
*       X            1                   * 
*                    2                   * 
*                    3             X     * 
*                    4                   * 
*                    5                   * 
*                    6                   * 
*                    7                   * 
*                    8                   * 
*****************************************/
// Looking for O, Xs are points 
void testDeceptiveNNOneLevel()
{
    output_header("testDeceptiveNNOneLevel()",
                  "tests for nearest neighbors across the dividing line");

    double coords[6][2] = {{-15, 7}, {6, 7}, {-13, -1}, {-5, 0}, {14, -3}, {14, 2}};
    double targetCoords[2] = {-13,1};
    double expectedCoords[2] = {-13,-1};

    vector< Point<2> > points;
    for (int i = 0; i < 6; ++i)
        points.push_back(Point<2>(coords[i]));
    Point<2> target(targetCoords);
    Point<2> expected(expectedCoords);

    KDTree<2> tree(points);
    tree.printTree(cout, color_scheme, 3);
    cout << "  ~    ~    ~    ~    ~    ~    ~" << endl;

    cout << "findNearestNeighbor(" << target << ") result   = "
         << tree.findNearestNeighbor(target) << endl;
    cout << "findNearestNeighbor(" << target << ") expected = "
         << expected << endl;
    
    cout << endl;
}



 /***********************
 *    X      8          * 
 *           7          * 
 *       X   6          * 
 *     S  X             * 
 *      N    X          * 
 *                      * 
 *           2          * 
 *           1          * 
 * 098765432101 X 567890* 
 *           1          * 
 *           2          * 
 *           3     M    * 
 *           4          * 
 *           5   X      * 
 *           6      M   * 
 *           7 M        * 
 ***********************/
// M: mine
// S: search target
// N: nearest neighbor
// X: non-mine elements
/**
 * returns true if nearest neighbor search of the kdree created by the 
 * parameter vector of elements returns an element that is equal to the 
 * expected element and false otherwise. The mine trigger is used to enable
 * all the mines. If the kdtree atempts to search subtrees of the kdtree
 * when it doesn't need to, the mine will "explode" resulting in a segmentation 
 * fault.
 */
void testMines()
{
    output_header("testMines()",
                  "tests that you don't look at nodes you don't need to");

    //                              NN
    double coords[10][2] = {{-8, 7}, {-6, 4}, {-5, 6}, {-3, 5}, {0, 7}, 
                           {2, -7}, {3, 0}, {5, -4}, {6, -3}, {7, -6}};
    //                     M        M       M        M        M
    bool isMine[10] = { false, false, false, false, false, true, true, true, true, true };
    double targetCoords[2] = {-7,5};
    double expectedCoords[2] = {-6,4};

    vector< Point<2> > points;
    for (int i = 0; i < 10; ++i)
        points.push_back(Point<2>(coords[i], isMine[i]));
    Point<2> target(targetCoords);
    Point<2> expected(expectedCoords);
    
    KDTree<2> tree(points);
    tree.printTree(cout, color_scheme);
    cout << "  ~    ~    ~    ~    ~    ~    ~" << endl;

    // Turn on land mines to make sure we don't step on them
    Point<2>::enable_mines = true;
    cout << "findNearestNeighbor(" << target << ") result   = "
         << tree.findNearestNeighbor(target) << endl;
    cout << "findNearestNeighbor(" << target << ") expected = "
         << expected << endl;
    Point<2>::enable_mines = false;
    
    cout << endl;
}

void testDeceptiveMines()
{
    output_header("testDeceptiveMines()",
                  "tests fence jumping with land mines");

    double coords[20][2] = {
        {84, 44}, // mine
        {74, 0},  // mine
        {54, 62}, // mine
        {59, 0},  // mine
        {34, 15}, // mine
        {42, 63},
        {96, 56}, // mine
        {44, 79},
        {44, 43},
        {28, 10}, // mine
        {60, 30}, // mine
        {88, 72}, // mine
        {75, 68}, // mine
        {43, 65},
        {48, 0},  // mine
        {14, 15}, // mine
        {49, 83},
        {50, 35},
        {95, 50}, // mine
        {82, 20}};// mine
    bool isMine[20] = { 1, 1, 1, 1, 1, 0, 1, 0, 0, 1, 1, 1, 1, 0, 1, 1, 0, 0, 1, 1};
    double targetCoords[2] = {45, 59};
    double expectedCoords[2] = {42, 63};

    vector< Point<2> > points;
    for (int i = 0; i < 20; ++i)
        points.push_back(Point<2>(coords[i], isMine[i]));
    Point<2> target(targetCoords);
    Point<2> expected(expectedCoords);
    
    KDTree<2> tree(points);
    tree.printTree(cout, color_scheme);
    cout << "  ~    ~    ~    ~    ~    ~    ~" << endl;

    // Turn on land mines to make sure we don't step on them
    Point<2>::enable_mines = true;
    cout << "findNearestNeighbor(" << target << ") result   = "
         << tree.findNearestNeighbor(target) << endl;
    cout << "findNearestNeighbor(" << target << ") expected = "
         << expected << endl;
    Point<2>::enable_mines = false;
    
    cout << endl;
}



int main(int argc, char** argv)
{
    // set global bools for colored output
    color_scheme = colored_out::DISABLE;
    is_terminal  = isatty(STDOUT_FILENO);
    is_colored   = (argc > 1 && tolower(argv[1][0]) == 'c') && is_terminal;
    if (is_terminal) color_scheme = colored_out::ENABLE;

    // colored output magic
    colored_out coloroutput;
    if (is_colored)
    {
        coloroutput.set_expected_file("soln_testkdtree.out");
        int status = coloroutput.start();
        if (status < 0) return 0;
    }

    // test cases
    testLinearCtor<1>(10);
    testLinearNNS<1>(10);
    testLinearCtor<3>(31);
    testLinearNNS<3>(31);
    testDeceptiveNNOneLevel();
    testMines();
    testDeceptiveMines();
}

