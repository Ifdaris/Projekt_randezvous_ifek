#include <iostream>
#include <fstream>
#include "Agent.h"
/*
int losowy(vector<Vertex_>& graf, int& current, vector<bool>& visited) {
    srand(static_cast<unsigned int> (time(nullptr)));
    visited[current] = true;
    const vector<int>& sasiedzi = graf[current].getNeighbour();
    vector<int> nieodwiedzeni;
    for (int s : sasiedzi) {
        if (!visited[s]) {
            nieodwiedzeni.push_back(s);
        }
    }
    int next = current;

    if (!nieodwiedzeni.empty()) {
        next = nieodwiedzeni[rand() % nieodwiedzeni.size()];
    }
    else if (!sasiedzi.empty()) {
        next = sasiedzi[rand() % sasiedzi.size()];
    }
    return next;
}
*/

/*
void Agent_dfs::move(vector<Vertex_>& graf) {
    while (!stack.empty()) {
        int u_id = stack.top();
        stack.pop();
        if (!visited[u_id]) {
            visited[u_id] = true;
            current_vertex = graf[u_id];
            const std::vector<int>& neighbour = graf[u_id].getNeighbour();
            for (int sasiad_id : neighbour) {
                if (!visited[sasiad_id]) {
                    stack.push(sasiad_id);
                }
            }
            return;
        }
    }
}

*/
void Agent_dfs::move(std::vector<Vertex_>& graf) {

    // 1. Sprawdź, czy praca w ogóle się nie skończyła
    if (stack.empty()) {
        return;
    }

    // 2. Weź ID ze szczytu i ZDEJMIJ je
    int u_id = stack.top();
    stack.pop();

    // 3. FIZYCZNIE PRZESUŃ agenta w to miejsce
    //    Teraz agent zawsze pokazuje, co było na 'top'
    current_vertex = graf[u_id];

    // 4. Dopiero teraz sprawdź, czy to miejsce jest nowe
    if (!visited[u_id]) {

        // To nowe miejsce! Oznacz je...
        visited[u_id] = true;

        // ...i dodaj wszystkich sąsiadów na stos
        const std::vector<int>& neighbour = graf[u_id].getNeighbour();
        for (int sasiad_id : neighbour) {
            if (!visited[sasiad_id]) {
                stack.push(sasiad_id);
            }
        }
    }

    // 5. A jeśli (if) było fałszywe (miejsce było 'visited')?
    //    To nic! Agent po prostu cofnął się tam wizualnie.
    //    Następne wywołanie 'move' weźmie kolejny
    //    element ze stosu (który jest jeszcze "głębiej" wstecz).

    // 6. Zakończ ruch (return jest niepotrzebny na końcu funkcji void)
}