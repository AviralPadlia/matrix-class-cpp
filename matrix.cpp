#include<iostream>
#include<iomanip>

using namespace std;

class Matrix
{
  int rows,cols;
  int **mat;

  void create();
  void input();
  void free();

 public:
  Matrix();

  void set();
  void set(int);
  void set(int,int);
  void set(int,int,int);
  void set(const Matrix &);
  void print() const;

  int isSqrMatrix() const;
  int isNullMatrix() const; 
  int isUnitMatrix() const;
  int isIdentityMatrix() const;
  int isSymmetricMatrix() const;
  int equals(const Matrix &) const;

  Matrix getTranspose() const;          //t=m.getTranspose();
  void transposeOf(const Matrix &);     //t.transposeOf(m);

  Matrix add(const Matrix &) const;
  int add(const Matrix &,const Matrix &);

  Matrix subtract(const Matrix &) const;
  int subtract(const Matrix &,const Matrix &);

  Matrix multiply(const Matrix &) const;
  int multiply(const Matrix &,const Matrix &);
};

Matrix::Matrix()
{
 rows=cols=0;
}

void Matrix::create()
{
 if(rows<=0||cols<=0)
 {
  rows=cols=0;
  return;
 }
 mat=new int*[rows];
 for(int i=0;i<rows;i++)
  mat[i]=new int[cols];
}

void Matrix::input()
{
 cout<<"\n";

 for(int i=0;i<rows;i++)
 {
  for(int j=0;j<cols;j++)
  {
   cout<<"Item ["<<i<<","<<j<<"] : ";
   cin>>mat[i][j];
  }
  cout<<"\n";
 }
}

void Matrix::free()
{
 if(rows)
 {
  for(int i=0;i<rows;i++)
   delete mat[i];

  delete mat;
  rows=cols=0;
 }
}

void Matrix::set()
{
 free();
 cout<<"\n";
 cout<<"Enter the No. of Rows : ";
 cin>>rows;
 cout<<"Enter the No. of Cols : ";
 cin>>cols;

 create();
 input();
}

void Matrix::set(int n)
{
 free();
 rows=cols=n;
 create();
 input();
}

void Matrix::set(int r,int c)
{
 free();
 rows=r;
 cols=c;
 create();
 input();
}

void Matrix::set(int r,int c,int n)
{
 free();
 rows=r;
 cols=c;
 create();
 for(int i=0;i<rows;i++)
  for(int j=0;j<cols;j++)
   mat[i][j]=n;
}

void Matrix::set(const Matrix &m)
{
 free();
 rows=m.rows;
 cols=m.cols;
 create();
 for(int i=0;i<rows;i++)
  for(int j=0;j<cols;j++)
   mat[i][j]=m.mat[i][j];
}

void Matrix::print() const
{
 cout<<"\n";
 for(int i=0;i<rows;i++)
 {
  for(int j=0;j<cols;j++)
  {
   cout<<setw(5)<<mat[i][j]<<" ";
  }
 }
}

int Matrix::isSqrMatrix() const
{
 return rows && rows==cols;
}

int Matrix::isNullMatrix() const
{
 if(rows==0) return 0;
 for(int i=0;i<rows;i++)
 {
  for(int j=0;j<cols;j++)
  {
   if(mat[i][j]!=0)return 0;
  }
 }
 return 1;
}

int Matrix::isUnitMatrix() const
{
 if(rows==0) return 0;
 for(int i=0;i<rows;i++)
 {
  for(int j=0;j<cols;j++)
  {
   if(mat[i][j]!=1)return 0;
  }
 }
 return 1;
}

int Matrix::isIdentityMatrix() const
{
 if(!isSqrMatrix()) return 0;
 for(int i=0;i<rows;i++)
 {
  for(int j=0;j<cols;j++)
  {
   if(i==j&&mat[i][j]!=1||i!=j && mat[i][j]!=0)
   return 0;
  }
 }
 return 1;
}

int Matrix::isSymmetricMatrix() const
{
 if(!isSqrMatrix()) return 0;
 for(int i=0;i<rows;i++)
 {
  for(int j=0;j<cols;j++)
  {
   if(mat[i][j]!=mat[j][i])
   return 0;
  }
 }
 return 1;
}

int Matrix::equals(const Matrix &m) const
{
 if(rows!=m.rows||cols!=m.cols) return 0;
 for(int i=0;i<rows;i++)
 {
  for(int j=0;j<cols;j++)
  {
   if(mat[i][j]!=m.mat[i][j]) return 0;
  }
 }
 return 1;
}

Matrix Matrix::getTranspose() const
{
 Matrix m;
 m.rows=cols;
 m.cols=rows;
 m.create();
 for(int i=0;i<m.rows;i++)
 {
  for(int j=0;j<m.cols;j++)
  {
   m.mat[i][j]=mat[j][i];
  }
 }
 return m;
}

void Matrix::transposeOf(const Matrix &m)
{
 free();
 rows=m.cols;
 cols=m.rows;
 create();
 for(int i=0;i<rows;i++)
 {
  for(int j=0;j<cols;j++)
  {
   mat[i][j]=m.mat[j][i];
  }
 }
}

Matrix Matrix::add(const Matrix &x) const
{
 Matrix m;
 if(rows!=x.rows||cols!=x.cols) return m;
 m.rows=rows;
 m.cols=cols;
 m.create();
 for(int i=0;i<rows;i++)
  for(int j=0;j<cols;j++)
   m.mat[i][j]=mat[i][j]+x.mat[i][j];
 return m;
}

int Matrix::add(const Matrix &x,const Matrix &y)
{
 free();
 if(x.rows!=y.rows||x.cols !=y.cols) return 0;
 rows=x.rows;
 cols=x.cols;
 create();
 for(int i=0;i<rows;i++)
  for(int j=0;j<cols;j++)
   mat[i][j]=x.mat[i][j]+y.mat[i][j];
 return 1;
}

Matrix Matrix::subtract(const Matrix &x) const
{
 Matrix m;
 if(rows!=x.rows||cols!=x.cols) return m;
 m.rows=rows;
 m.cols=cols;
 m.create();
 for(int i=0;i<rows;i++)
  for(int j=0;j<cols;j++)
   m.mat[i][j]=mat[i][j]-x.mat[i][j];
 return m;
}

int Matrix::subtract(const Matrix &x,const Matrix &y)
{
 free();
 if(x.rows!=y.rows||x.cols !=y.cols) return 0;
 rows=x.rows;
 cols=x.cols;
 create();
 for(int i=0;i<rows;i++)
  for(int j=0;j<cols;j++)
   mat[i][j]=x.mat[i][j]-y.mat[i][j];
 return 1;
}

Matrix Matrix::multiply(const Matrix &x) const
{
 Matrix m;
 if(cols!=x.rows)return m;
 m.rows=rows;
 m.cols=x.cols;
 m.create();
 for(int i=0;i<m.rows;i++)
  for(int j=0;j<m.cols;j++)
  {
   m.mat[i][j]=0;
   for(int k=0;k<cols;k++)    
    m.mat[i][j]=m.mat[i][j]+mat[i][k]*x.mat[k][j];
  }
 return m;
}

int Matrix::multiply(const Matrix &x,const Matrix &y)
{
 free();
 if(x.cols!=y.rows)return 0;
 rows=x.rows;
 cols=y.cols;
 create();
 for(int i=0;i<rows;i++)
  for(int j=0;j<cols;j++)
  {
   mat[i][j]=0;
   for(int k=0;k<x.cols;k++)    
    mat[i][j]=mat[i][j]+x.mat[i][k]*y.mat[k][j];
  }
 return 1;
}

main()
{
 Matrix x;

 x.set();
 x.set(3);
 x.set(3,4);
 x.set(3,4,1);

 Matrix y;

 y=x.getTranspose();
 y.transposeOf(x);
}
