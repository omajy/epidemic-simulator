# Epidemic Simulation in C++ 🦠

## Technologies 💻
**Language:** C++

**Libraries:** C++ Standard Library

## Overview ⚡

This project implements a stochastic agent-based epidemic simulator in C++ to model the spread of infectious disease through a population.

Each member of the population is represented as an individual `Person` object with attributes including age, susceptibility, and health status.

Disease transmission is simulated through a configurable number of random daily interactions between individuals.

The simulation tracks the progression of an outbreak over time, including susceptible, infected, recovered, and deceased populations.

Stochastic sampling is used throughout the simulation through the C++ random library, allowing identical disease and population configurations to produce different epidemic trajectories.

## Features 🧬

- Agent-based population modelling
- Randomised population generation
- Susceptible, infected, recovered, and deceased health states
- Configurable disease transmission probability
- Configurable infectious duration
- Configurable mortality rate
- Random daily contact simulation
- Individual infection duration tracking
- Stochastic transmission modelling using Monte Carlo sampling

## Simulation Model 📈

For each contact between an infected and susceptible individual, transmission probability is calculated as:

`Individual Susceptibility × Disease Transmission Probability`

A random probability sample determines whether transmission occurs.

New infections are applied after the current simulation day has completed, preventing newly infected individuals from transmitting the disease until the following day.

Once an individual's infectious duration has elapsed, a mortality probability determines whether they recover or become deceased.

## Example Output 🔬

```text
---------------------
Day: 28
Susceptible: 412
Infected: 33
Recovered: 55
Deceased: 0
---------------------
Day: 29
Susceptible: 408
Infected: 34
Recovered: 58
Deceased: 0
---------------------
Day: 30
Susceptible: 402
Infected: 38
Recovered: 60
Deceased: 0
---------------------
