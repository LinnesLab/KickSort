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
	
	//From: https://forum.arduino.cc/index.php?topic=280486.0
	static void combSort(Type input[], const uint16_t samples);
	static void combSort(Type input[], const uint16_t samples, KickSort_Dir d);
	
	//From: https://forum.arduino.cc/index.php?topic=280486.0
	static void shellSort(Type input[], const uint16_t samples);
	static void shellSort(Type input[], const uint16_t samples, KickSort_Dir d);

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


template<typename Type>
void KickSort<Type>::insertionSort(Type input[], const uint16_t samples)
{
	uint16_t t;
	uint16_t z;
	Type temp;
	
	for (t = 1; t < samples; t++)
	{
		z = t;
		while( (z > 0) && (input[z] < input[z - 1] ))
		{
			temp = input[z];
			input[z] = input[z - 1];
			input[z - 1] = temp;
			z--;
		}
	}
	
}


template<typename Type>
void KickSort<Type>::insertionSort(Type input[], const uint16_t samples, KickSort_Dir d)
{
	if(d == KickSort_Dir::ASCENDING) insertionSort(input, samples);
	else
	{
		uint16_t t;
		uint16_t z;
		Type temp;
		
		for (t = 1; t < samples; t++)
		{
			z = t;
			while( (z > 0) && (input[z] > input[z - 1] ))
			{
				temp = input[z];
				input[z] = input[z - 1];
				input[z - 1] = temp;
				z--;
			}
		}
	}
}


template<typename Type>
void KickSort<Type>::combSort(Type input[], const uint16_t samples)
{
	uint16_t i;
	uint16_t j;
	uint16_t gap;
	uint8_t swapped = 1;
	Type temp;
	
	gap = samples;
	while (gap > 1 || swapped == 1)
	{
		gap = gap * 10 / 13;
		if (gap == 9 || gap == 10) gap = 11;
		if (gap < 1) gap = 1;
		swapped = 0;
		
		for (i = 0, j = gap; j < samples; i++, j++)
		{
			if (input[i] > input[j])
			{
				temp = input[i];
				input[i] = input[j];
				input[j] = temp;
				
				swapped = 1;
			}
		}
	}
}


template<typename Type>
void KickSort<Type>::combSort(Type input[], const uint16_t samples, KickSort_Dir d)
{
	if(d == KickSort_Dir::ASCENDING) combSort(input, samples);
	else
	{
		uint16_t i;
		uint16_t j;
		uint16_t gap;
		uint8_t swapped = 1;
		Type temp;
		
		gap = samples;
		while (gap > 1 || swapped == 1)
		{
			gap = gap * 10 / 13;
			if (gap == 9 || gap == 10) gap = 11;
			if (gap < 1) gap = 1;
			swapped = 0;
			
			for (i = 0, j = gap; j < samples; i++, j++)
			{
				if (input[i] < input[j])
				{
					temp = input[i];
					input[i] = input[j];
					input[j] = temp;
					
					swapped = 1;
				}
			}
		}
	}
}


template<typename Type>
void KickSort<Type>::shellSort(Type input[], const uint16_t samples)
{
	uint16_t i;
	uint16_t d = samples;
	uint8_t flag = 1;
	Type temp;
	
	
	while( flag || (d > 1)) // boolean flag (true when not equal to 0)
	{
		flag = 0; // reset flag to 0 to check for future swaps
		d = (d+1) / 2;
		
		for (i = 0; i < (samples - d); i++)
		{
			if (input[i + d] < input[i])
			{
				temp = input[i + d]; // swap positions i+d and i
				input[i + d] = input[i];
				input[i] = temp;
				flag = 1; // tells swap has occurred
			}
		}
	}
}


template<typename Type>
void KickSort<Type>::shellSort(Type input[], const uint16_t samples, KickSort_Dir d)
{
	if(d == KickSort_Dir::ASCENDING) shellSort(input, samples);
	else
	{
		uint16_t i;
		uint16_t d = samples;
		uint8_t flag = 1;
		Type temp;
		
		
		while( flag || (d > 1)) // boolean flag (true when not equal to 0)
		{
			flag = 0; // reset flag to 0 to check for future swaps
			d = (d+1) / 2;
			
			for (i = 0; i < (samples - d); i++)
			{
				if (input[i + d] > input[i])
				{
					temp = input[i + d]; // swap positions i+d and i
					input[i + d] = input[i];
					input[i] = temp;
					flag = 1; // tells swap has occurred
				}
			}
		}
	}
	
}



#endif /* KickSort_h */
