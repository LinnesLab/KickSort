//
//  KickSort.h
//  
//
//  Created by Orlando Hoilett on 8/22/20.
//

#ifndef KickSort_h
#define KickSort_h


//Standard Arduino libraries
#include <Arduino.h>


enum class KickSort_Dir
{
	ASCENDING = 0,
	DESCENDING = 1
};


template<typename Type>

class KickSort
{

public:
	
	//From: https://github.com/dndubins/QuickStats
	static void bubbleSort(Type input[], const uint16_t samples);
	static void bubbleSort(Type input[], const uint16_t samples, KickSort_Dir d);
	
	//From: https://forum.arduino.cc/index.php?topic=280486.0
	static void quickSort(Type input[], const uint16_t samples);
	static void quickSort(Type input[], const uint16_t samples, KickSort_Dir d);
	
	//From: https://forum.arduino.cc/index.php?topic=280486.0
	static void insertionSort(Type input[], const uint16_t samples);
	static void insertionSort(Type input[], const uint16_t samples, KickSort_Dir d);

};



//Default ascending
//From: https://github.com/dndubins/QuickStats
template<typename Type>
void KickSort<Type>::bubbleSort(Type input[], const uint16_t samples)
{
	uint32_t newn = 0;
	uint32_t n = samples;
	Type temp = 0;
	
	//if newn doesn't increment past 1, then array is already sorted and we
	//will exit the loop
	do {
		newn = 1;
		
		for(uint16_t p = 1; p < samples; p++)
		{
			if(input[p-1] > input[p])
			{
				//swap places in array
				temp = input[p];
				input[p] = input[p-1];
				input[p-1] = temp;
				
				//update index
				newn = p;
			}
		}
		
		n = newn;
	} while(n > 1);
}


//From: https://github.com/dndubins/QuickStats
template<typename Type>
void KickSort<Type>::bubbleSort(Type input[], const uint16_t samples, KickSort_Dir d)
{
	if(d == KickSort_Dir::ASCENDING) bubbleSort(input, samples);
	else
	{
		uint32_t newn = 0;
		uint32_t n = samples;
		Type temp = 0;
		
		//if newn doesn't increment past 1, then array is already sorted and we
		//will exit the loop
		do {
			newn = 1;
			
			for(uint16_t p = 1; p < samples; p++)
			{
				if(input[p-1] < input[p])
				{
					//swap places in array
					temp = input[p];
					input[p] = input[p-1];
					input[p-1] = temp;
					
					//update index
					newn = p;
				}
			}
			
			n = newn;
		} while(n > 1);
	}
}


//From: https://forum.arduino.cc/index.php?topic=280486.0
template<typename Type>
void KickSort<Type>::quickSort(Type input[], const uint16_t samples)
{
	if (samples < 2) return;
	
	Type p = input[samples / 2];
	Type *l = input; //left index
	Type *r = input + samples - 1; //right index
	
	while (l <= r)
	{
		if (*l < p) l++;
		else if (*r > p) r--;
		else
		{
			Type t = *l;
			*l = *r;
			*r = t;
			l++;
			r--;
		}
	}
	
	
	//Recursive call
	quickSort(input, r - input + 1);
	quickSort(l, input + samples - l);
}


//From: https://forum.arduino.cc/index.php?topic=280486.0
template<typename Type>
void KickSort<Type>::quickSort(Type input[], const uint16_t samples, KickSort_Dir d)
{
	if(d == KickSort_Dir::ASCENDING) quickSort(input, samples);
	else
	{
		if (samples < 2) return;
		
		Type p = input[samples / 2];
		Type *l = input; //left index
		Type *r = input + samples - 1; //right index
		
		while (l <= r)
		{
			if (*l > p) l++;
			else if (*r < p) r--;
			else
			{
				Type t = *l;
				*l = *r;
				*r = t;
				l++;
				r--;
			}
		}
		
		
		//Recursive call
		quickSort(input, r - input + 1, d);
		quickSort(l, input + samples - l, d);
	}
}



#endif /* KickSort_h */
