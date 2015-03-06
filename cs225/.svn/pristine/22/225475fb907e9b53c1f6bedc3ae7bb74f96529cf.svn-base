
// height()
template <typename T>
int BinaryTree<T>::height() const
{
	// Call recursive helper function on root
	return height(root);
}

// height() recursive helper function
template <typename T>
int BinaryTree<T>::height(const Node * subRoot) const
{
	// Base case
	if (subRoot == NULL) return -1;
	
	// Recursive definition
	return 1 + max(height(subRoot->left), height(subRoot->right));
}



// printLeftToRight()
template <typename T>
void BinaryTree<T>::printLeftToRight() const
{
	// Call recursive helper function on the root
	printLeftToRight(root);

	// Finish the line
	cout << endl;
}

// printLeftToRight() recursive helper function
template <typename T>
void BinaryTree<T>::printLeftToRight(const Node * subRoot) const
{
	// Base case - null node
	if (subRoot == NULL)
		return;

	// Print left subtree
	printLeftToRight(subRoot->left);

	// Print this node
	cout << subRoot->elem << ' ';

	// Print right subtree
	printLeftToRight(subRoot->right);
}



// mirror()
template <typename T>
void BinaryTree<T>::mirror()
{
	mirror(root);
}

// mirror() recursive helper function
template <typename T>
void BinaryTree<T>::mirror(Node * subRoot)
{
        Node * temp;
	// Base case - null node
	if (subRoot == NULL)
		return;


	temp=subRoot->left;
        subRoot->left=subRoot->right;
        subRoot->right=temp;
        temp=subRoot->left;
        mirror(temp);
	temp=subRoot->right;
        mirror(temp);      




}



// isOrdered()
template <typename T>
bool BinaryTree<T>::isOrdered() const
{
       bool a=isOrdered(root);
       return a;
	
}

// isordered() recursive helper function
template <typename T>
bool BinaryTree<T>::isOrdered(const Node * subRoot) const
{
        Node * temp1;
        Node * temp2;
        bool test1=true;
        bool test2=true;
	// Base case - null node
	if (subRoot == NULL)
		return true;

        temp1=subRoot->left;
        temp2=subRoot->right;
        if (temp1!=NULL) {
         if (temp1->elem > subRoot->elem) {
             test1=false;
         }
        }
        if (temp2!=NULL) {
         if (subRoot->elem > temp2->elem) {
             test2=false;
         }
        }
        if ( (test1)&&(test2)&&(isOrdered(temp1))&&(isOrdered(temp2)) ) {
          return true;
           }
        else {
 return false;
}
        
          


}



// printPathSums()
template <typename T>
void BinaryTree<T>::printPaths() const
{
	// Your code here
}



// sumDistances()
template <typename T>
int BinaryTree<T>::sumDistances() const
{
	return -1; // Your code here
}

