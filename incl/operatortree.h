#ifndef OPERATORTREE_H
#define OPERATORTREE_H

#include <string>
#include <vector>
#include "operatornode.h"

class OperatorTree
{
public:
	OperatorTree(const std::string &expression);
	~OperatorTree();

	std::vector<const OperatorNode*> getNodesInOrder() const;
	bool parsingFailed() const;

private:
	const std::string m_expression;
	OperatorNode *m_rootNode;
	bool m_parsingFailed;
};

#endif
