class Solution {
public:
    void printLL(Node* head) {
        while (head != NULL) {
            cout << head->data << " ";
            head = head->next;
        }
    }
    Node* deleteNthNodeFromEnd(Node* head, int N) {
        if (head == NULL) {
            return NULL;
        }

        int cnt = 0;
        Node* temp = head;

        while (temp != NULL) {
            cnt++;
            temp = temp->next;
        }

        if (cnt == N) {
            Node* newHead = head->next;
            delete head; 
            return newHead;
        }

        int res = cnt - N;
        temp = head;


        while (temp != NULL) {
            res--;
            if (res == 0) {
                break;
            }
            temp = temp->next;
        }

        Node* delNode = temp->next;
        temp->next = temp->next->next;
        delete delNode; 

        return head;
    }
};
