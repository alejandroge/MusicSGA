#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char FLAG = 0;
const unsigned short NPARAMS = 16;
const unsigned short NIND = 100;
const unsigned short NBITS[] = {4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4};
const float P_MUTATION = 0.001;
const float CROSSPROB = 0.8;
#define LLIMIT 0
#define ULIMIT 8
double RANGE = ULIMIT - LLIMIT;
#define GLIMIT 500
#define ERROR 0.001
//const unsigned short SAMPLE[] = { 15, 13, 11, 13, 11, 15, 13, 11, 13, 15, 13, 11, 13, 15, 13, 11};
const unsigned short SAMPLE[] = { 11, 9, 13, 11, 9, 13, 11, 9, 11, 10, 13, 11, 10, 13, 11, 10};

#include "INDIVIDUAL-init.h"
#include "POPULATION-init.h"
#include "POPULATION-eval.h"
#include "SELECTION.h"
#include "CROSSING.h"
#include "MUTATION.h"
#include "ELITISM.h"
#include "WRITTER.h"

int main(int argc, char const *argv[]) {
  //srand(time(NULL));
  INDIVIDUAL * ppltn, * newPpltn, bestInd;
  unsigned short nGeneration = 1, i, nCrossed;
  unsigned short ** Crosstable, * newInds;
  int x, y;

  newInds = (unsigned short *)malloc(NIND*sizeof(unsigned short));

  ppltn = allocPopulation();
  newPpltn = allocPopulation();
  if(ppltn == NULL || newPpltn == NULL) return 1;

  // Initialize Population
  if( initPopulation(ppltn) == 1 || initPopulation(newPpltn) == 1){
    printf("Cannot initialize individual properly\n");
    return 1;
  }

  // EvaluatePopulation returns a pointer to the better individual of the population
  bestInd = EvaluatePopulation(ppltn);
  //showGeneration(ppltn);
  // Stop condition
  while(nGeneration < GLIMIT /*&& bestInd->fitness > ERROR*/) {

    //printf("\n\tGeneration %u\n", nGeneration+1);
    Crosstable=rouletteSelection(ppltn, Crosstable);
    //printf("Cross table computed\n");
    nCrossed = crossPopulation(ppltn, newPpltn, Crosstable, newInds);
    //printf("Population crossed\n");
    MutatePopulation(ppltn, newInds, nCrossed);
    Elitism(bestInd, ppltn);
    bestInd = EvaluatePopulation(ppltn);
    //showGeneration(ppltn);
    nGeneration++;
  }
  printf("\nBest Individual, generation %u\n", nGeneration);
  //showGenes(bestInd);
  //showFitness(bestInd);
  printf("\t"); showIndividual(&bestInd);
  Writter(&bestInd);

  //showPopulation(ppltn);

  return 0;
}
