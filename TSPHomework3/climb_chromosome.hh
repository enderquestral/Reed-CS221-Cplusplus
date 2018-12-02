//INHERITS FROM CHROMOSOME CLASS, OVERRIDES MUTATE AND CLONE

#pragma once
#include "chromosome.hh"
#include "cities.hh"

class ClimbChromosome: public Chromosome
{
    public:
        //ClimbChromosome(const Cities*);
        ClimbChromosome(const Cities* cities_ptr_temp)
         : Chromosome(cities_ptr_temp)
        {}

        virtual ~ClimbChromosome() = default;


        //OVERRIDES ONLY THESE TWO
        void mutate() override;

        Chromosome* clone() const override
        {
            return new ClimbChromosome(cities_ptr_);
        }

};
