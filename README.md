# DVC-Course-Map
We will be making and implementing a map data structure template class. 
We will use our map to design an application to increase the functionality of Assignment 6. 
The map will store values in association with unique keys, which can be used to access the user’s desired information quickly and efficiently. 
As previously noted, keys must be unique, but values can be repeated. The keys must share a data type. 
Entering a value with an already existing key will overwrite the entry at the existing key. 
Our map will have functions to find values and return their keys, find keys and return their values, return the size of the map, determine 
whether the map is empty or not, add elements to the map, delete elements from the map, and clear the map. Data will be retrieved in constant time. 
Because each key is unique and stores one value, our map will be able to look at the memory address specified by the key without searching and 
return the stored value in constant time. If there were key collisions, some fallback method would have to be devised to store a new given value, 
and a variable amount of time would be spent searching for said value because it would not be in the expected place. To avoid collisions, we will 
overwrite the value for a given key if a new value is input with the same key. Maps are particularly useful data structures which have widespread 
applications. Analogs to our map template data structure already exist in C++ and other programming languages. For instance, the Standard Template 
Library has map, Java has HashMap, HashTable, and TreeMap, and Python has dictionary.. Maps are particularly useful when dealing with associations 
of unique values with other information. 

Examples include: driver’s licenses, identification numbers, dictionaries, postal codes, bank accounts, 
license plates, and so on.  Our program will use a menu interface to let the user search for and add specific terms, specific subjects, and specific 
classes, along with information about those classes. This program would also be helpful for Diablo Valley College by avoiding duplicates using unique 
section numbers as keys, any duplicate entries will merely overwrite existing information. The way we will implement this functionality is by using 
nested maps, with the highest level map pairing terms with their subject offerings, and the middle level map pairing subjects with the section numbers 
of the classes offered, and the lowest level pairing section numbers with information about the classes. We could also use our map to organize class 
information according to the names of the professors who taught those classes, and search for all the classes a professor has taught.  

Conclusion: Our project proposal is to further improve upon our previous assignment that handled displaying class information at DVC through the
use of maps. By using maps, this new program will have better efficiency and far more functionality than before. 
(something like this)  ^^(End with a conclusion (1-2 statements) that summarizes your project proposal and refers back to the thesis statement)
