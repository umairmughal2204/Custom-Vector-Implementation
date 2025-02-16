# include <iostream>
# include<string>
# include "Vector.cpp"
int main()
{
    Vector<int> myVector(3); 
    int choice;
    do
    {
        cout << "\n----- Menu -----" << endl;
        cout << "1. Push Back" << endl;
        cout << "2. Pop Back" << endl;
        cout << "3. Insert" << endl;
        cout << "4. Erase" << endl;
        cout << "5. Sort" << endl;
        cout << "6. Move" << endl;
        cout << "7. Union of Vectors" << endl;
        cout << "8. ersection of Vectors" << endl;
        cout << "9. Unique" << endl;
        cout << "10. Subset" << endl;
        cout << "11. Search" << endl;
        cout << "12. Prstring Vector" << endl;
        cout << "13. Vector Addition (+)" << endl;
        cout << "14. Vector Subtraction (-)" << endl;
        cout << "15. Vector Equality (==)" << endl;
        cout << "16. Vector Greater Than (>)" << endl;
        cout << "17. Vector Less Than (<)" << endl;
        cout << "18. Access Vector Element ([])" << endl;
        cout << "19. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int num;
            cout << "Enter the element to push back: ";
            cin >> num;
            myVector.push_back(num);
            break;
        }
        case 2:
        {
            int popped = myVector.pop_back();
            cout << "Popped element: " << popped << endl;
            break;
        }
        case 3:
        {
            int num;
            int index;
            cout << "Enter the element to insert: ";
            cin >> num;
            cout << "Enter the index to insert at: ";
            cin >> index;
            myVector.insert(num, index);
            break;
        }
        case 4:
        {
            try
            {
                int index;
                cout << "Enter the index to erase: ";
                cin >> index;
                int erased = myVector.erase(index);
                cout << "Erased element: " << erased << endl;
                break;
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n';
                break;
            }
        }
        case 5:
            myVector.sort();
            cout << "Vector sorted." << endl;
            break;
        case 6:
        {
            int num;
            cout << "Enter the number of positions to move: ";
            cin >> num;
            myVector.move(num);
            cout << "Vector moved." << endl;
            break;
        }
        case 7:
        {
            Vector<int> otherVector;
            cout << "Enter elements for the other vector:" << endl;
            cin >> otherVector;
            Vector<int> unionVector = myVector.unionOfVectors(otherVector);
            cout << "Union of vectors: " << unionVector << endl;
            break;
        }
        case 8:
        {
            Vector<int> otherVector;
            cout << "Enter elements for the other vector:" << endl;
            cin >> otherVector;
            Vector<int> stringersectionVector = myVector.intersectionOfVectors(otherVector);
            cout << "stringersection of vectors: " << stringersectionVector << endl;
            break;
        }
        case 9:
        {
            Vector<int> uniqueVector = myVector.unique();
            cout << "Unique elements in the vector: " << uniqueVector << endl;
            break;
        }
        case 10:
        {
            Vector<int> otherVector;
            cout << "Enter elements for the other vector:" << endl;
            cin >> otherVector;
            if (myVector.subset(otherVector))
                cout << "The vector is a subset of the other vector." << endl;
            else
                cout << "The vector is not a subset of the other vector." << endl;
            break;
        }
        case 11:
        {
            int key;
            cout << "Enter the key to search: ";
            cin >> key;
            if (myVector.search(key))
                cout << "Key found in the vector." << endl;
            else
                cout << "Key not found in the vector." << endl;
            break;
        }
        case 12:
            cout << "Vector elements: " << myVector << endl;
            break;
        case 13:
            {
                Vector<int> otherVector;
                cout << "Enter elements for the second vector:\n";
                cin >> otherVector;
                Vector<int> result = myVector + otherVector;
                cout << "Result of addition: " << result << endl;
            }
            break;
        case 14:
            {
                Vector<int> otherVector;
                cout << "Enter elements for the second vector:\n";
                cin >> otherVector;
                Vector<int> result = myVector - otherVector;
                cout << "Result of subtraction: " << result << endl;
            }
            break;
        case 15:
            {
                Vector<int> otherVector;
                cout << "Enter elements for the second vector:\n";
                cin >> otherVector;
                if (myVector == otherVector)
                    cout << "Vectors are equal." << endl;
                else
                    cout << "Vectors are not equal." << endl;
            }
            break;
        case 16:
            {
                Vector<int> otherVector;
                cout << "Enter elements for the second vector:\n";
                cin >> otherVector;
                if (myVector > otherVector)
                    cout << "First vector is greater than the second vector." << endl;
                else
                    cout << "First vector is not greater than the second vector." << endl;
            }
            break;
        case 17:
            {
                Vector<int> otherVector;
                cout << "Enter elements for the second vector:\n";
                cin >> otherVector;
                if (myVector < otherVector)
                    cout << "First vector is less than the second vector." << endl;
                else
                    cout << "First vector is not less than the second vector." << endl;
            }
            break;
        case 18:
            {
                int index;
                cout << "Enter index to access: ";
                cin >> index;
                try
                {
                    cout << "Element at index " << index << ": " << myVector[index] << endl;
                }
                catch (const exception &e)
                {
                    cerr << "Error: " << e.what() << endl;
                }
            }
            break;
        case 19:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 19);
    return 0; 
}
