#pragma once
using namespace System;
using namespace System::Drawing;

#include "math.h"
#include "_List.h"

int min(int a, int b)
{
	if(a < b)
		return a;
	else
		return b;
}

#define NULL 0

struct Point_{
	int x,y;
	Point_(int xi = 0, int yi = 0): x(xi), y(yi) {}
};

const int Radius = 10;

ref class Vertex{
	Pen^ pen;
public:
	int x,y;
	int Number;
	Vertex(void )
	{
		x = y = -1;
		Number = -1;
		pen = gcnew Pen(Color::Red);
	}
	Vertex(int xi, int yi, int Num): x(xi), y(yi), Number(Num)
	{
		pen = gcnew Pen(Color::Red);
	}
	void Draw(BufferedGraphics ^buff)
	{
		Font^ drawFont = gcnew Font( "Arial",12 );
		SolidBrush^ drawBrush = gcnew SolidBrush( Color::Green );

		buff->Graphics->DrawEllipse(pen, x-Radius, y-Radius, Radius*2, Radius*2);
		buff->Graphics->DrawString(Convert::ToString(Number), drawFont, drawBrush, x-Radius+3, y-Radius+1);
	}
};

ref class Graf
{
	int** adj_matr; // adjacency matrix - матрица смежности
	array<Vertex^>^ V;
	int CountEdge;
	int CountVertex;
	int CurrentCountV;
	Pen^ pen;
public:
	// Properties
	bool Oriented;
	bool Weighted;
	//------------
private:
	void Init()
	{
		if(CountVertex > 0)
		{
			adj_matr = new int*[CountVertex];
			for(int i=0; i<CountVertex; i++)
				adj_matr[i] = new int[CountVertex];

			for(int i=0; i<CountVertex; i++)
				for(int j=0; j<CountVertex; j++)
					adj_matr[i][j] = 0;

			V = gcnew array<Vertex^>(CountVertex);
		}
		else
		{
			adj_matr = NULL;
			V = nullptr;
		}
	}


	// --------  Отрисовка стрелки -------------
	void rotate(Point_& br, float ang)
	{
		float k = br.x ;
		br.x = cos(ang)*br.x-sin(ang)*br.y;
		br.y = sin(ang)*k+cos(ang)*br.y;
	}

	void DrawArrow(BufferedGraphics ^buff, Point_ a, Point_ b, bool double_arrow, int col)
	{
		if(col > 1000)
			pen->Color = Color::Orange;
		else
			pen->Color = Color::Blue;
		Point_ tr[4];
		for(int i=0; i<4; i++)
			tr[i] = 0;

		float dx, dy, dl;
		dx = b.x - a.x;
		dy = b.y - a.y;
		float ang = atan(dy/dx);
		if (dx < 0 && dy < 0 || dx < 0 && dy > 0) ang = ang+3.14;
		if (dy == 0 && dx < 0) ang = 3.14;
		dl = sqrt(dx*dx+dy*dy);
		if (dl < 40) {
			tr[2].x = /*dl/2*/20;
			tr[2].y = /*dl/8*/5;
		} else
		{
			tr[2].x = dl-20/*-dl/120*/;
			tr[2].y = 5/*+dl/120*/;
		}
		tr[1].x = dl;
		tr[3].x = tr[2].x;
		tr[3].y = -tr[2].y;
		for(int i=0; i<4; i++)
		{
			rotate(tr[i], ang);
			tr[i].x += a.x;
			tr[i].y += a.y;
		}
		buff->Graphics->DrawLine(pen, tr[0].x, tr[0].y, tr[1].x, tr[1].y);
		buff->Graphics->DrawLine(pen, tr[1].x, tr[1].y, tr[2].x, tr[2].y);
		buff->Graphics->DrawLine(pen, tr[2].x, tr[2].y, tr[3].x, tr[3].y);
		buff->Graphics->DrawLine(pen, tr[3].x, tr[3].y, tr[1].x, tr[1].y);

		if(double_arrow)
		{
			for(int i=0; i<4; i++)
				tr[i] = 0;
			dx = a.x - b.x;
			dy = a.y - b.y;
			ang = atan(dy/dx);
			if (dx < 0 && dy < 0 || dx < 0 && dy > 0) ang = ang+3.14;
			if (dy == 0 && dx < 0) ang = 3.14;

			if (dl < 40) {
				tr[2].x = /*dl/2*/20;
				tr[2].y = /*dl/8*/5;
			} else
			{
				tr[2].x = dl-20/*-dl/120*/;
				tr[2].y = 5/*+dl/120*/;
			}
			tr[1].x = dl;
			tr[3].x = tr[2].x;
			tr[3].y = -tr[2].y;
			for(int i=0; i<4; i++)
			{
				rotate(tr[i], ang);
				tr[i].x += b.x;
				tr[i].y += b.y;
			}
			buff->Graphics->DrawLine(pen, tr[1].x, tr[1].y, tr[2].x, tr[2].y);
			buff->Graphics->DrawLine(pen, tr[2].x, tr[2].y, tr[3].x, tr[3].y);
			buff->Graphics->DrawLine(pen, tr[3].x, tr[3].y, tr[1].x, tr[1].y);
		}
	}
	// ------------------------------------
	void PaintWay(int* Way)
	{
		if(Way == NULL)
			return;
		int i=0;
		while(Way[i+1] != -1)
		{
			adj_matr[Way[i]][Way[i+1]] += 1000;
			i++;
		}
	}

	void PaintEdges(int* Edge)
	{
		if(Edge == NULL)
			return;
		int i=0;
		while(Edge[2*i] != -1)
		{
			adj_matr[Edge[2*i]][Edge[2*i+1]] += 1000;
			i++;
		}
	}

	void DiscolorEdge()
	{
		for(int i=0; i<CurrentCountV; i++)
			for(int j=0; j<CurrentCountV; j++)
				if(adj_matr[i][j] > 0)
					adj_matr[i][j] = 1;
	}

public:

	Graf(void)
	{
		CountVertex = 0;
		CurrentCountV = 0;
		CountEdge = 0;
		Oriented = true;
		Weighted = false;
		adj_matr = NULL;
		V = nullptr;
		pen = gcnew Pen(Color::Blue);
	}

	Graf(int CountVertex_)
	{
		CountVertex = CountVertex_;
		CurrentCountV = 0;
		CountEdge = 0;
		Oriented = true;
		Weighted = false;
		Init();
		pen = gcnew Pen(Color::Blue);
	}

	void Add(int x, int y)
	{
		if(CurrentCountV == CountVertex)
			return;

		V[CurrentCountV] = gcnew Vertex(x, y, CurrentCountV); // всегда добавляем вершину со следующим номером
		CurrentCountV++;
	}

	bool AddEdge(int anum, int bnum, int weight)
	{
		if(anum < CurrentCountV && anum >= 0 && bnum < CurrentCountV && bnum >= 0)
		{
			if(Oriented)
				adj_matr[ anum ][ bnum ] = weight;
			else
			{
				adj_matr[ anum ][ bnum ] = weight;
				adj_matr[ bnum ][ anum ] = weight;
			}
			CountEdge++;
		}
		else return false;
	}

	Vertex^ GetVertex(int x, int y)
	{
		for(int i=0; i<CurrentCountV; i++)
			if( sqrt( (double)abs(x-V[i]->x)*abs(x-V[i]->x) + abs(y-V[i]->y)*abs(y-V[i]->y) ) < Radius )
				return V[i];
		return nullptr;
	}

	int* FindWay(int anum, int bnum)
	{
		if(anum >= CurrentCountV || anum < 0 || bnum >= CurrentCountV || bnum < 0)
		{
			DiscolorEdge();
			return NULL;
		}
		bool* VisitedV = new bool[CountVertex];
		for (int i=0; i<CountVertex; i++)
			VisitedV[i] = false;
		int* StackV = new int[CountVertex];
		int sptr = 0; // индекс вершины стека
		bool Flag = false;
		int cur_num = anum;
		while( cur_num != bnum )
		{
			for(int i=0; i<CurrentCountV; i++)
			{
				if(i == cur_num)
					continue;
				if(adj_matr[cur_num][i] > 0 && VisitedV[i] == false)
				{
					StackV[sptr++] = cur_num;
					VisitedV[cur_num] = true;
					cur_num = i;
					Flag = true;
					break;
				}
			}
			if(Flag == false) // если не нашли, то переходить не куда - отступим назад
			{
				if(cur_num == anum) // пришли назад и не нашли
				{
					DiscolorEdge();
					return NULL;
				}
				VisitedV[cur_num] = true;
				cur_num = StackV[sptr-1];
				sptr--;
			}
			Flag = false;
		}
		StackV[sptr] = bnum; // конец пути
		StackV[sptr+1] = -1; // конец пути
		DiscolorEdge();
		PaintWay(StackV);
		return StackV;
	}

	int* FindMinOstSubgraph()
	{
		DiscolorEdge();
		MyList edge;
		int ECount = 0, OstWeigth = 0, CmpnCount = CurrentCountV;
		int* CmpnArr = new int[CmpnCount];
		for(int i=0; i<CmpnCount; i++)
			CmpnArr[i] = i;
		
		for(int i=0; i<CurrentCountV; i++)
			for (int j=i+1; j<CurrentCountV; j++)
				if(adj_matr[i][j] > 0)
				{
					ECount++;
					edge.Add(ECount, adj_matr[i][j], i, j);
				}

		int* OstSubgEdge = new int[ECount*2];
		int OstEdgeCount = 0;
		edge.Sort();
		item* t = edge.GetHead();
		while(CmpnCount > 1)
		{
			int temp;
			if( CmpnArr[t->va] != CmpnArr[t->vb] )
			{
				temp = CmpnArr[t->va];
				for(int i=0; i<CmpnCount; i++)
					if(CmpnArr[i] == temp)
						CmpnArr[i] = CmpnArr[t->vb];
				OstSubgEdge[2*OstEdgeCount] = t->va;
				OstSubgEdge[2*OstEdgeCount+1] = t->vb;
				OstEdgeCount++;
				OstWeigth += t->Value;
				CmpnCount--;
			}
			t = t->next;
			if(t == NULL)
				break;
		}
		OstSubgEdge[2*OstEdgeCount] = -1;
		OstSubgEdge[2*OstEdgeCount+1] = OstWeigth;
		PaintEdges(OstSubgEdge);
		return OstSubgEdge;
	}
	
	void Clear()
	{
		CurrentCountV = 0;
		for(int i=0; i<CountVertex; i++)
			for (int j=0; j<CountVertex; j++)
				adj_matr[i][j] = 0;
	}

	void Draw(BufferedGraphics ^buff)
	{
		for(int i=0; i<CurrentCountV; i++)
			V[i]->Draw(buff);

		for(int i=0; i<CurrentCountV; i++)
			for (int j=i+1; j<CurrentCountV; j++)
			{
				if( adj_matr[i][j] > 0 || adj_matr[j][i] > 0 )
				{
					if(adj_matr[i][j] > 1000)
						pen->Color = Color::Orange;
					else
						pen->Color = Color::Blue;

					if(Oriented)
					{
						Point_ p1(V[i]->x, V[i]->y);
						Point_ p2(V[j]->x, V[j]->y);
						if( adj_matr[i][j] > 0 && adj_matr[j][i] > 0 ) // тогда стрелка в обе стороны
							DrawArrow(buff, p1, p2, true, adj_matr[i][j]+adj_matr[j][i]-1);
						else
						{
							if( adj_matr[i][j] > 0 )
								DrawArrow(buff, p1, p2, false, adj_matr[i][j]);
							if( adj_matr[j][i] > 0 )
								DrawArrow(buff, p2, p1, false, adj_matr[j][i]);
						}
					}
					else
					{
						buff->Graphics->DrawLine(pen, V[i]->x, V[i]->y, V[j]->x, V[j]->y);
					}

					if(Weighted)
					{
						Font^ drawFont = gcnew Font( "Arial",12 );
						SolidBrush^ drawBrush = gcnew SolidBrush( Color::DarkViolet );
						buff->Graphics->DrawString( Convert::ToString(adj_matr[i][j]%100), drawFont, drawBrush, 
							min(V[i]->x,V[j]->x) + abs(V[i]->x-V[j]->x)/2, min(V[i]->y,V[j]->y) + abs(V[i]->y-V[j]->y)/2);
					}
					
				}
			}
	}

};

