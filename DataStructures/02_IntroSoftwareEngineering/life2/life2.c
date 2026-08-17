#include "life2.h"

/* ================================================================================================
 * user_says_yes:   get input from the user to determine if we should move on to the next
 *                  generation.
 * Pre:             The last generation has just finished.
 * Post:            The program will either move on to the next generation, or terminate.
 * Uses:            None
 * */
bool user_says_yes(void)
{
    char user_input;

    while (true)
    {
        while ((user_input = getchar()) == '\n');
        if (user_input == 'y' || 'Y') return true;
        else if (user_input == 'n' || 'N') return false;
        else printf("Incorrect input, please try again.\n");
    }
}


void write_map(Grid grid)
{

}

void find_size(int *rows, int *cols)
{

}

void read_map(List *list, Grid grid)
{

}

void kill(ListEntry cell)
{

}

/* ================================================================================================
 * vivify:  Vivify cell if applicable.
 * Pre:     The cell is a candidate to become alive.
 * Post:    Checks that the cell meet all requirements to become alive. If not, no change is made.
 *          If so, then cell is added to the list newlive, and the array map is updated.
 * Uses:    Function list_add, array n_neighbors, changes array map and list newlive as global
 *          variables.
 */
void vivify(ListEntry cell)
{
    if (map[cell.row][cell.col] == DEAD &&
        n_neighbors[cell.row][cell.col] == 3)
    {
        if (cell.row >= 1 &&
            cell.row <= maxrow &&
            cell.col >= 1 &&
            cell.col <= maxcol) // not on the hedge
        {
            map[cell.row][cell.col] = ALIVE;
            list_add(cell, &newlive);
        }
    }
}

/* ================================================================================================
 * add_neighbors:   adjust neighbor counts of vivified cell.
 * Pre:             cell has just become alive.
 * Post:            array n_neighbors has increased counts for all cells neighboring cell. If the
 *                  increased neighbor count makes the cell a candidate to become vivified then
 *                  the cell has been added to list maylive. If the neighbor count makes the cell
 *                  a candidate to die, the it is added to list maydie.
 * Uses:            Function list_add; changes array n_neighbors and lists maylive and maydie as
 *                  global variables.
 */
void add_neighbors(ListEntry cell)
{
    int n_row, n_col; // loop indices for neighbors of cell
    Cell neighbor;   // structure to hold neighbor

    for (n_row = cell.row - 1; n_row <= cell.row + 1; n_row++)
    {
        for (n_col = cell.col - 1; n_col <= cell.col + 1; n_col++)
        {
            if (n_row != cell.row || n_col != cell.col) // skip current cell
            {
                n_neighbors[n_row][n_col]++;

                switch (n_neighbors[n_row][n_col])
                {
                    case 0:
                        Error("Impossible case for add_neighbors.");
                        break;
                    case 3:
                        if (map[n_row][n_col] == DEAD)
                        {
                            neighbor.row = n_row; // coordinate record
                            neighbor.col = n_col;
                            list_add(neighbor, &maylive);
                        }
                        break;
                    case 4:
                        if (map[n_row][n_col] == ALIVE)
                        {
                            neighbor.row = n_row; // coordinate record
                            neighbor.col = n_col;
                            list_add(neighbor, &maydie);
                        }
                        break;
                }
            }
        }
    }
}

/* ================================================================================================
 * subtract_neighbors:  adjusts neighbor counts of a cell that died.
 * Pre:                 cell has just died.
 * Post:                array n_neighbors has reduced counts for each cell neighboring cell. If
 *                      the new neighbor counts makes a neighboring cell a candidate to die, it is
 *                      added to the list maydie. If the new neighbor count makes the cell a 
 *                      candidate to become alive, it is added to the list maylive.
 * Uses:                Function list_add; changes array n_neighbors and lists maylive and maydie 
 *                      as global variables.
 */
void subtract_neighbors(ListEntry cell)
{
    int n_row, n_col; // loop indices for neighbors of cell
    Cell neighbor;   // structure to hold neighbor

    for (n_row = cell.row - 1; n_row <= cell.row + 1; n_row++)
    {
        for (n_col = cell.col - 1; n_col <= cell.col + 1; n_col++)
        {
            if (n_row != cell.row || n_col != cell.col) // skip current cell
            {
                n_neighbors[n_row][n_col]++;

                switch (n_neighbors[n_row][n_col])
                {
                    case 0:
                        Error("Impossible case for add_neighbors.");
                        break;
                    case 3:
                        if (map[n_row][n_col] == DEAD)
                        {
                            neighbor.row = n_row; // coordinate record
                            neighbor.col = n_col;
                            list_add(neighbor, &maylive);
                        }
                        break;
                    case 4:
                        if (map[n_row][n_col] == ALIVE)
                        {
                            neighbor.row = n_row; // coordinate record
                            neighbor.col = n_col;
                            list_add(neighbor, &maydie);
                        }
                        break;
                }
            }
        }
    }
}

/* ================================================================================================
 * initialize:  initialize life game.
 * Pre:         None.
 * Post:        array map contains the initial configuration of living and dead cells. array
 *              n_neighbors contains counts of living neighbors corresponding to the
 *              configuration in array map. List maylive contains only dead cells and includes
 *              all candidates that may be vivified in the first generation. List maydie contains
 *              only living cells and contains all candidates that may die in the first generation
 *              Lists newlive and newdie are empty.
 * Uses:        Simple list package, functions find_size, read_map, add_neighbors
 */
void initialize(Grid map, Gridcount n_neighbors,
                List *newlive, List *newdie, List *maylive, List *maydie)
{
    // the following variables are used to set all entries in n_neighbors to 0
    int row, col;

    list_create(newlive);
    list_create(newdie);
    list_create(maylive);
    list_create(maydie);

    // put out an initial message and find bounds for the grid
    find_size(&maxrow, &maxcol);

    // obtain the initial configuration
    read_map(newlive, map);

    // set all entries in n_neighbors to 0
    for (row = 0; row <= maxrow + 1; row++)
        for (col = 0; col <= maxcol + 1; col++)
            n_neighbors[row][col] = 0;

    // put all the candidates to live into maylive
    list_traverse(newlive, add_neighbors);

    // check all the living cells to see which die
    list_copy(maydie, newlive);

    list_clear(newlive);
}
