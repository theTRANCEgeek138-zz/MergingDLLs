//Merging two sorted Doubly Linked Lists (DLLs) into a new sorted DLL

#include <stdio.h>
#include <stdlib.h>

typedef struct ELEMENT
{
    int Value;
    struct ELEMENT *next;
    struct ELEMENT *prev;
} NODE;

//This function adds input data to a Node
void SetNodeData (NODE *TargetNode, int SetValue, NODE *SetNext, NODE *SetPrev)
{
    if (TargetNode == NULL) return;
    TargetNode->Value= SetValue;
    TargetNode->next= SetNext;
    TargetNode->prev= SetPrev;
}

//This function creates a new Node after the current position
NODE *AddNode (int InpDat, NODE *CurrNode)
{
    //Allocate new Node
    NODE *NewNode= (NODE*) malloc (sizeof (NODE));
    //Set new Node data
    SetNodeData (NewNode,InpDat,NULL,CurrNode);
    //Link new Node to the current Node
    if (CurrNode != NULL) CurrNode->next= NewNode;
    //Return pointer to the New Node
    return (NewNode);
}

//This function prints Linked List data 
void PrintList (NODE StartNode)
{
    NODE *PrintObject= StartNode.next;
    while (PrintObject != NULL)
    {
        printf ("%d ",PrintObject->Value);
        PrintObject= PrintObject->next;
    }
}

//This function takes two lists' nodes, compares 'em and return the smaller node
NODE *NodeComparator (NODE *Node1, NODE *Node2)
{
    if (Node1 == NULL) return(Node2);
    if (Node2 == NULL) return (Node1);

    //Compare two Nodes' value
    if (Node1->Value > Node2->Value) return (Node2);
    else return (Node1);
}

//This function merges two linked lists
//Return value is the starting Node of the final result list
NODE MergeLists (NODE StartNodeList1, NODE StartNodeList2)
{
    //Create starting Node of final result
    NODE StartNodeFinal;
    SetNodeData (&StartNodeFinal,0,NULL,NULL);

    //Set Beginning positions for two input lists
    NODE *Object= StartNodeList1.next;
    NODE *Candidate= StartNodeList2.next;
    
    //Create and initiate the Current Node position of the final result list
    NODE *FinalListCurrNode= &StartNodeFinal;
    while ((Object != NULL) || (Candidate != NULL))
    {
        //Find new Node for the final result
        NODE *NewFinalListNode;
        NewFinalListNode= NodeComparator (Object, Candidate);

        //Browse to the next Node in either Object or Candiate
        //Elaboration: if the pointer result of Comparator function is a Node in which List, move to the next node in that list
        if (NewFinalListNode == Object) Object= Object->next;
        else Candidate= Candidate->next;

        //Add new Node to the final list (Link new Node to the Current Node of the final list)
        FinalListCurrNode->next= NewFinalListNode;
        //Link New node to the prev Node
        NewFinalListNode->prev= FinalListCurrNode;
        //Set Current Node to the added Node for the next Node
        FinalListCurrNode= NewFinalListNode;
    }
    return (StartNodeFinal);
}

int main()
{
    int n1, n2;
    NODE LIST1STARTNODE;
    NODE LIST2STARTNODE;
    NODE *CurrentNode;
    SetNodeData (&LIST1STARTNODE,0,NULL,NULL);
    SetNodeData (&LIST2STARTNODE,0,NULL,NULL);

    //Input first list
    printf ("1ST LIST\n");
    CurrentNode= &LIST1STARTNODE;
    scanf ("%d",&n1);
    for (int i=0;i<n1;i++)
    {
        int m;
        scanf ("%d",&m);
        CurrentNode= AddNode (m,CurrentNode);
    }

    //Input second list
    printf ("2ND LIST\n");
    CurrentNode= &LIST2STARTNODE;
    scanf ("%d",&n2);
    for (int i=0;i<n2;i++)
    {
        int m;
        scanf ("%d",&m);
        CurrentNode= AddNode (m,CurrentNode);
    }

    //Print first list
    PrintList (LIST1STARTNODE);
    printf ("\n");
    //Print second list
    PrintList (LIST2STARTNODE);
    printf ("\n");

    NODE FLISTSTARTNODE;
    FLISTSTARTNODE= MergeLists (LIST1STARTNODE, LIST2STARTNODE);
    PrintList (FLISTSTARTNODE);
    
    printf ("\n End of Program");
    return 0;
}