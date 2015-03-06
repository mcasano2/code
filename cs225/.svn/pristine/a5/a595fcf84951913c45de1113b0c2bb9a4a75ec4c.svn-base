//============================================================
//   file: fills.cpp
//   description: implementation file for fills
//   date: 15 Mar 2011
//   Machine Problem 4.2
//============================================================


// inputs are img, x, y, fillColor, tolerance, frameFreq
// returns animation called myAnim of DFS/BFS fills
animation DFSfill(BMP& img, int x, int y, colorPicker & fillColor, int tolerance, int frameFreq) {
	int i,j;          // used as counters for loops to clear processed array
	animation myAnim; // holds our animation of the fill
	Stack<int> myStack; // stack to implement depth first search fill fill
	int dist; // used to calculate manhattan distance
	int animCounter=0; // counter to keep track of processed frames
	int width= img.TellWidth();  // width of BMP
	int height= img.TellHeight();  // height of BMP
	bool done[width][height];   // array to indicate processed points
	RGBApixel orig;             // for saving color at center pixel
	RGBApixel color;            // gets colorpicker return values
//save original pixel color information
	orig.Red=img(x,y)->Red;
	orig.Green=img(x,y)->Green;
	orig.Blue=img(x,y)->Blue;
// clear processed array
	for (i=0; i<width; i++) {
		for (j=0; j<height; j++) {
			done[i][j]=0;
		}
	}
// push center pixel coordinates on stack
	myStack.push(x);
	myStack.push(y);
// process stack until empty
	while ( !myStack.isEmpty() ) {
	// pop off x,y in reverse order
		y= myStack.pop();
		x= myStack.pop();
		// square RGB space difference
		dist= (img(x,y)->Red-orig.Red)*(img(x,y)->Red-orig.Red)
			+     (img(x,y)->Green-orig.Green)*(img(x,y)->Green-orig.Green)
			+     (img(x,y)->Blue-orig.Blue)*(img(x,y)->Blue-orig.Blue);
// conditional to execute fill or not
		if ( (dist <= tolerance)&&(!done[x][y]) ) {
		 // functor to choose colorpicker
			color=fillColor(x,y);
			// saves returned color to x,y on BMP
			img(x,y)->Red=color.Red;
			img(x,y)->Blue=color.Blue;
			img(x,y)->Green=color.Green;
// increment processed counter
			animCounter=animCounter+1;
			// add others, test for bounds
			if ( ((x+1)<width)&&(!done[x+1][y]) ) {
				myStack.push(x+1);
				myStack.push(y);
			}
			if ( ((y+1)<height)&&(!done[x][y+1]) ) {
				myStack.push(x);
				myStack.push(y+1);
			}
			if ( ((x-1)>=0)&&(!done[x-1][y]) ) {
				myStack.push(x-1);
				myStack.push(y);
			}
			if ( ((y-1)>=0)&&(!done[x][y-1]) ) {
				myStack.push(x);
				myStack.push(y-1);
			}
			// test frameFreq
			if (animCounter==frameFreq) {
				myAnim.addFrame(img);
				animCounter=0;
			}
			// update point as processed
			done[x][y]=true;
		}
	}
	return myAnim;
}


animation BFSfill(BMP& img, int x, int y, colorPicker & fillColor, int tolerance, int frameFreq) {
// same implementation as DFSfill, except Stack is replaced by a queue
	int i,j;
	animation myAnim;
	Queue<int> myQueue;
	int dist;
	int animCounter=0;
	int width= img.TellWidth();
	int height= img.TellHeight();
	bool done[width][height];
	RGBApixel orig;
	RGBApixel color;
//save original pixel color information
	orig.Red=img(x,y)->Red;
	orig.Green=img(x,y)->Green;
	orig.Blue=img(x,y)->Blue;
// clear processed array
	for (i=0; i<width; i++) {
		for (j=0; j<height; j++) {
			done[i][j]=0;
		}
	}
// push center pixel coordinates on stack
	myQueue.enqueue(x);
	myQueue.enqueue(y);
// process queue until empty
	while ( !myQueue.isEmpty() ) {
		x= myQueue.dequeue();
		y= myQueue.dequeue();
		dist= (img(x,y)->Red-orig.Red)*(img(x,y)->Red-orig.Red)
			+     (img(x,y)->Green-orig.Green)*(img(x,y)->Green-orig.Green)
			+     (img(x,y)->Blue-orig.Blue)*(img(x,y)->Blue-orig.Blue);
// conditional to execute fill or not
		if ( (dist <= tolerance)&&(!done[x][y]) ) {
			color=fillColor(x,y);
			img(x,y)->Red=color.Red;
			img(x,y)->Blue=color.Blue;
			img(x,y)->Green=color.Green;
			animCounter=animCounter+1;
			// add others
			if ( ((x+1)<width)&&(!done[x+1][y]) ) {
				myQueue.enqueue(x+1);
				myQueue.enqueue(y);
			}
			if ( ((y+1)<height)&&(!done[x][y+1]) ) {
				myQueue.enqueue(x);
				myQueue.enqueue(y+1);
			}
			if ( ((x-1)>=0)&&(!done[x-1][y]) ) {
				myQueue.enqueue(x-1);
				myQueue.enqueue(y);
			}
			if ( ((y-1)>=0)&&(!done[x][y-1]) ) {
				myQueue.enqueue(x);
				myQueue.enqueue(y-1);
			}
			// test frameFreq
			if (animCounter==frameFreq) {
				myAnim.addFrame(img);
				animCounter=0;
			}
			done[x][y]=true;
		}
	}
	// return animation
	return myAnim;
}

// implements DFS solid fill
animation DFSfillSolid(BMP& img, int x, int y, RGBApixel fillColor, int tolerance, int frameFreq) {
	animation myAnim;
	solidColorPicker mySolid(fillColor);
	myAnim=DFSfill(img,x,y,mySolid,tolerance,frameFreq);
	return myAnim;
}

// implements DFS grid fill
animation DFSfillGrid(BMP& img, int x, int y, RGBApixel gridColor, int gridSpacing, int tolerance, int frameFreq) {
	animation myAnim;
	gridColorPicker myGrid(gridColor,gridSpacing);
	myAnim=DFSfill(img,x,y,myGrid,tolerance,frameFreq);
	return myAnim;
}

// implements DFS gradient fill
animation DFSfillGradient(BMP& img, int x, int y, RGBApixel fadeColor1, RGBApixel fadeColor2,
		int radius, int tolerance, int frameFreq) {
	animation myAnim;
	gradientColorPicker myGradient(fadeColor1,fadeColor2,radius,x,y);
	myAnim=DFSfill(img,x,y,myGradient,tolerance,frameFreq);
	return myAnim;
}
// implements BFS solid fill
animation BFSfillSolid(BMP& img, int x, int y, RGBApixel fillColor, int tolerance, int frameFreq) {
	animation myAnim;
	solidColorPicker mySolid(fillColor);
	myAnim=BFSfill(img,x,y,mySolid,tolerance,frameFreq);
	return myAnim;
}

// implements BFS grid fill
animation BFSfillGrid(BMP& img, int x, int y, RGBApixel gridColor, int gridSpacing, int tolerance, int frameFreq) {
	animation myAnim;
	gridColorPicker myGrid(gridColor,gridSpacing);
	myAnim=BFSfill(img,x,y,myGrid,tolerance,frameFreq);
	return myAnim;
}

// implements BFS gradient fill
animation BFSfillGradient(BMP& img, int x, int y, RGBApixel fadeColor1, RGBApixel fadeColor2,
		int radius, int tolerance, int frameFreq) {
	animation myAnim;
	gradientColorPicker myGradient(fadeColor1,fadeColor2,radius,x,y);
	myAnim=BFSfill(img,x,y,myGradient,tolerance,frameFreq);
	return myAnim;
}
