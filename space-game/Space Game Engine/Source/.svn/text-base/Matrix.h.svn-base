#pragma once

template <class Type>

//This class is to make a 2d array by using a 1 dimensional array.
class matrix{
public:
	matrix ()//empty constructor, just in case they dont call the other one
	{
		width = 0;
		height = 0;
		myArray = new Type[0];
	}
	matrix (unsigned int x,unsigned int y)
	{
		//set up our dimensions
		width = x;
		height = y;

		myArray = new Type[x * y];
	}
	~matrix()
	{
		delete [] myArray;//deallocate everything
	}

	//operator overload so when () is used you can assign stuff, for example myMatrix(5, 5) = 4
	Type& operator() (unsigned int x, unsigned int y)
	{
		if (x < width && y < height)//bounds checking
		{
			return myArray[y * width + x];
		}
		else
		{
			return myArray[0];//If they were asking for something out of bounds...
														//give them first item in the array
		}
	}

	int getWidth()//return the width
	{
		return width;
	}
	int getHeight()//return the height
	{
		return height;
	}
	void resize (unsigned int x, unsigned int y)//resize the array
	{
		Type* newArray = new Type[x * y];
		delete [] myArray;//delete the old stuff

		myArray = newArray;
		width = x;
		height = y;
	}

private:
	unsigned int width;
	unsigned int height;
	Type* myArray;
		
};