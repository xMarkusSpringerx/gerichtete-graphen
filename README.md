# Gerichtete Graphen
## 1. Representation von ungerichteten Graphen
Hinweise: Es werden nur Graphen mit einer fixen Anzahl n von Knoten betrachtet, d.h. die Anzahl der Knoten kann nicht wachsen oder schrumpfen und muß von Anfang an bekannt sein. Als “Knotennamen” können deshalb die ganzen Zahlen (int-Werte) von 1 .. n dienen.

a) Entwickeln Sie eine abstrakte Datenstruktur (in Form eines Moduls GraphAM.h + .c) zur Verwaltung eines Graphen mit n Knoten, wobei zur Repräsentation intern eine Adjazenzmatrix verwendet wird.

b) Entwickeln Sie eine abstrakte Datenstruktur (in Form eines Moduls GraphAL.h + .c) zur Verwaltung eines Graphen mit n Knoten, wobei zur Repräsentation intern eine Adjazenzliste verwendet wird.

Die Mindestfunktionalität umfasst in beiden Fällen das Initialisieren (insbesondere mit dem Parameter n), Kanten zwischen Knoten eintragen, Kanten zwischen Knoten löschen und die interne Darstellung des Graphen in geeigneter Form ausgeben. Achten Sie darauf, dass beide Datenstrukturen "austauschbar" sind, indem von einem Klienten anstelle der Datei GraphAM.h die Datei GraphAL.h inkludiert wird oder umgekehrt.

## 2. Gerichtete Graphen und topologisches Sortieren
Gerichtete Graphen sind u.a. für Navigationssysteme und Netzpläne von großer Bedeutung.
a) Ändern Sie Ihre abstrakten Datenstrukturen aus 1a und 1b so ab, dass Sie gerichtete Graphen damit darstellen können (wieder in Form von zwei Modulen DGraphAM.h + .c und DGraphAL.h + .c).
b) Implementieren Sie eine Prozedur
void TopSort(void);
die auf der Basis der in 2a erstellten Datenstrukturen für gerichtete Graphen die Knoten des gerichteten Graphen "topologisch sortiert" ausgibt. Durch das topologische Sortieren von Knoten eines Graphen wird eine sequentielle Liste von Knoten des Graphen in der Form erzeugt, dass wenn es eine gerichtete Kante von i nach j gibt, i in der Liste vor j steht.
