INDIVIDUAL EvaluatePopulation(INDIVIDUAL * ppltn);  // Iterates over the array of population
void EvaluateIndividual(INDIVIDUAL * ind);    // Inside here the evaluation function is set

INDIVIDUAL EvaluatePopulation(INDIVIDUAL * ppltn) {
  unsigned short i, bestIndex;

  // Compute fitness for each individual
  for(i=0; i<NIND; i++) {
    computeRealValues(ppltn+i);
    EvaluateIndividual(ppltn+i);
  } //printf("Population evaluated\n");

  // Looks for best fitness index
  bestIndex = 0;
  for(i=1; i<NIND; i++)
    if( ppltn[i].fitness > ppltn[bestIndex].fitness ) bestIndex = i;

  // returns Individual with the best fitness
  return ppltn[bestIndex];
}

void EvaluateIndividual(INDIVIDUAL * ind) {
  unsigned short i;
  float dist, aux;

  ind->fitness = 2;
  /*
    r G3 A3 B3 C4 D4 E4 F4 G4
    | | | | | | | |
    0 1 2 3 4 5 6 7

    Sample melody: 5 5 5 3 5 7 0 7

    The function to evaluate each individual is a list of different characteristics
    that describe the melody/individual. Currently it only checks for the starting,
    ending notes and the distance between the notes of the sample melody and the
    generated one */
  // 1.- Starting note
  if(ind->value[0] == SAMPLE[0]) ind->fitness += 1;
  // 2.- Ending note
  if(ind->value[NIND-1] == SAMPLE[NIND-1]) ind->fitness += 1;
  // 3.- Distance
  for(i=0; i<NPARAMS; i++) {
    aux = ind->value[i] - SAMPLE[i];
    if(aux<0) aux *= -1;
    dist += aux/7;
  } //printf("%f\n", dist/2);
  ind->fitness += dist/2;

  /* Alternative
  for(i=0; i<NIND; i++) {
    if(ind->value[i] == SAMPLE[i]) ind->fitness += 1;
  } */
}
