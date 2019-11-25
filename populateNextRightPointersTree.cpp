#include<bits/stdc++.h>
using namespace std;


void populateRightNeighbour(Tree*root) {
	if (root == NULL) return;

	if (root->left != NULL) {
		//agr left node ka right hai..toh left k neighbour me right  daal de
		if (root->right != NULL) {
			root->left->neighbour = root->right;
		}
// agr aisa nhi hai toh parent/root ke neighbour pr ja
		// aur uske bche ko root ke left mei daal de
		else {
			Tree*parentNeigbour = root->neighbour;
			Tree*neighbour;
			while (parentNeigbour != NULL) {
				neighbour = parentNeigbour->left ? parentNeigbour->left : parentNeigbour->right;
				if (neighbour != NULL) {
					root->left->neighbour = neighbour;
					break;
				}
				parentNeigbour = parentNeigbour->neighbour;
			}
		}
	}
	if (root->right != NULL) {
		//AGR RIGHT NULL NHI HAI TOH USMEI ROOT KE NEIGBOUR KA BCHA DAAL DO
		Tree*parentNeigbour = root->neighbour;
		Tree*neighbour;
		while (parentNeigbour != NULL) {
			neighbour = parentNeigbour->left ? parentNeigbour->left : parentNeigbour->right;
			if (neighbour != NULL) {
				root->right->neighbour = neighbour;
				break;
			}
			parentNeigbour = parentNeigbour->neighbour;
		}
	}
	
	//pehle right ko call kr 
	populateRightNeighbour(root->right);
	//fir left ko call kr
	populateRightNeighbour(root->left);
}

int main() {


	return 0;
}