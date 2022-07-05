#include "rever_local.h"
#include <stdlib.h>

void REVER_LOCAL::run_module(P_NODE* head)
{
	if (head = NULL)
		return;
	p1 = head;
	p2 = head->next;
	while (true)
	{
		if (p2 = NULL)
		{
			break;
		}
		else if (p1->next = NULL)
		{
			break;
		}
		p1->next = p2->next;
		p1 = p1->next;
		p2->next = p1->next;
		p1->next = p2;
		p1 = p1->next;
		p2 = p2->next;
	}

}