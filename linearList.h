/*
ͷ�ļ���
    ˳����һ��������
    ���з������Ǵ��麯��
*/
#ifndef linearList_
#define linearList_
#include <iostream>

using namespace std;

template<class T>
class linearList
{
public:
    // ��������
    virtual ~linearList() {};
    // �Ƿ�Ϊ��
    virtual bool empty() const = 0;
    // ���ر��Ԫ�ظ���
    virtual int size() const = 0;
    // ��������λ�õ���
    virtual T& get(int theIndex) const = 0;
    // ���ظ����ڱ��е�һ�γ��ֵ�λ��
    virtual int indexOf(const T& theElement) const = 0;
    // ɾ������λ�ô�����
    virtual void erase(int theIndex) = 0;
    // �������в���һ����
    virtual void insert(int theIndex, const T& theElement) = 0;
    // �����
    virtual void output(ostream& out) const = 0;
};
#endif