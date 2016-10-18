//
//  main.cpp
//  DSHomework1
//
//  Created by apple on 16/9/19.
//  Copyright © 2016年 YangZhiZhuang. All rights reserved.
//

#include <iostream>
#include <list>
template <class T>
class ArrayList
{
public:
    ArrayList(const int size);
    ~ArrayList(){delete[] arrayList;}
    void clear();
    int Length(){return curLen;}
    bool Append(const T value);
    //bool Insert(const int p,const T value);
    bool Delete(const int p);
    bool GetValue(const int p,T &value);
    T GetValue(const int p);
    bool SetValue(const int p,const T value);
    bool GetPos(int &p,const T value);
    int GetPos(const T value);
private:
    T *arrayList;
    int maxSize;
    int curLen;
};
template <class T>
ArrayList<T>::ArrayList(const int size)
{
    maxSize=size;
    arrayList=new T[maxSize];
    curLen=0;
}
template <class T>
bool ArrayList<T>::Append(const T value)
{
    if(curLen>=maxSize)
    {
        std::cout<<"Overflow"<<std::endl;
        return false;
    }
    else
    {
        arrayList[curLen++]=value;
        return true;
    }
}
template <class T>
void ArrayList<T>::clear()
{
    delete[] arrayList;
    curLen=0;
    arrayList=new T[maxSize];
}
template <class T>
bool ArrayList<T>::Delete(const int p)
{
    if(curLen<=0)
    {
        std::cout<<"No data to delete!"<<std::endl;
        return false;
    }
    else if(p<0||p>curLen-1)
    {
        std::cout<<"Address overflow!"<<std::endl;
        return false;
    }
    else
    {
        for(int i=p;i<curLen-1;i++)
            arrayList[i]=arrayList[i+1];
        curLen--;
        return true;
    }
}
template <class T>
bool ArrayList<T>::GetValue(const int p,T &value)
{
    if(p<0||p>curLen-1)
    {
        std::cout<<"Address overflow!"<<std::endl;
        return false;
    }
    else
    {
        value=arrayList[p];
        return true;
    }
}
template <class T>
T ArrayList<T>::GetValue(const int p)
{
    if(p<0||p>curLen-1)
    {
        std::cout<<"Address overflow!"<<std::endl;
        return arrayList[0];
    }
    else
    {
        return arrayList[p];
    }

}
template <class T>
bool ArrayList<T>::SetValue(const int p,const T value)
{
    if(p<0||p>curLen-1)
    {
        std::cout<<"Address overflow!"<<std::endl;
        return false;
    }
    else
    {
        arrayList[p]=value;
        return true;
    }
}
template <class T>
bool ArrayList<T>::GetPos(int &p,const T value)
{
    for(int i=0;i<curLen;i++)
        if(arrayList[i]==value)
        {
            p=i;
            return true;
        }
    p=-1;
    return false;
}
template <class T>
int ArrayList<T>::GetPos(const T value)
{
    for(int i=0;i<curLen;i++)
        if(arrayList[i]==value)
            return i;
    return -1;
}
int Question1(ArrayList<int> &arrayList)
{
    int min=arrayList.GetValue(0);
    int pos=0;
    for(int i=1;i<arrayList.Length();i++)
    {
        if(arrayList.GetValue(i)<min)
        {
            min=arrayList.GetValue(i);
            pos=i;
        }
    }
    while(arrayList.GetValue(arrayList.Length()-1)==min)
    {
        arrayList.Delete(arrayList.Length()-1);
    }
    arrayList.SetValue(pos, arrayList.GetValue(arrayList.Length()-1));
        for(int i=1;i<arrayList.Length();i++)
        {
            if(arrayList.GetValue(i)==min)
            {
                arrayList.SetValue(i, arrayList.GetValue(arrayList.Length()-1));
            }
        }
    arrayList.Delete(arrayList.Length()-1);
    
    return min;
}
void Question2(ArrayList<int> &arrayList,const int x)
{
        for(int i=0;i<arrayList.Length();i++)
        {
            if(arrayList.GetValue(i)==x)
            {
                arrayList.Delete(i);
                i--;
            }
        }
}
void Question3(ArrayList<int> &arrayList,const int s,const int t)
{
    for(int i=0;i<arrayList.Length();i++)
    {
        if(arrayList.GetValue(i)>s&&arrayList.GetValue(i)<t)
        {
            arrayList.Delete(i);
            i--;
        }
    }
}
int main(int argc, const char * argv[]) {
    
    ArrayList<int> arrayList(10);
    arrayList.Append(6);
    arrayList.Append(3);
    arrayList.Append(1);
    arrayList.Append(3);
    arrayList.Append(7);
    arrayList.Append(8);
    arrayList.Append(3);
    arrayList.Append(2);
    arrayList.Append(9);
    
    std::cout<<"初始化顺序表为："<<std::endl;
    for(int i=0;i<arrayList.Length();i++)
    {
        int temp;
        arrayList.GetValue(i, temp);
        std::cout<<temp<<"  ";
    }
    std::cout<<std::endl<<"问题1处理后返回值为"<<Question1(arrayList)<<",结果为："<<std::endl;
    for(int i=0;i<arrayList.Length();i++)
    {
        int temp;
        arrayList.GetValue(i, temp);
        std::cout<<temp<<"  ";
    }
    std::cout<<std::endl<<"问题2处理3后结果为："<<std::endl;
    Question2(arrayList,3);
    for(int i=0;i<arrayList.Length();i++)
    {
        int temp;
        arrayList.GetValue(i, temp);
        std::cout<<temp<<"  ";
    }
    std::cout<<std::endl<<"问题3处理s=5,t=9后结果为："<<std::endl;
    Question3(arrayList,5,9);
    for(int i=0;i<arrayList.Length();i++)
    {
        int temp;
        arrayList.GetValue(i, temp);
        std::cout<<temp<<"  ";
    }
    std::cout<<std::endl;
    return 0;
}
