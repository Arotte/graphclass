/** Adjacency Matrix class for representing graphs **/
#pragma once

class AdjMatrix {
	private:
		int n;
		int** data; /* Matrix holds integers */

		//int* visited;
	public:
		AdjMatrix(int);
		~AdjMatrix();

		/* Accessing operator */
		int& operator()(int x, int y) const { return data[x][y]; }

		/* Adding a column and a row to a matrix */
		void addColAndRow();
		/* Deletes a given row and column (square matrices) */
        void delColAndRow(int);
        /* Check if two adjacency matrices are the same */
        bool isEqual(AdjMatrix&) const;
        /* Makes two adjacency matrices the same */
        void equalTo(AdjMatrix&);


	/************** HELPER FUNCTIONS *****************/
	/* Memory allocator */
        void allocate(int** &ptr);
        /* Is null matrix? */
        bool isNullMatrix() const;
};
