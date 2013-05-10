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
	void parse(std::string expression);
	OperatorNode* parseRecursive(const std::string &expression);
	std::string::const_iterator findOpeningBracket(const std::string &expression);
	std::string::const_iterator findOpeningBracket(const std::string &expression, const std::string::const_iterator &start);
	std::string::const_iterator findClosingBracket(const std::string &expression, const std::string::const_iterator &openingBracket);
	std::vector<size_t> findMultiplicationsAndDivisions(const std::string &expression);
	std::vector<size_t> findAdditionsAndSubtractions(const std::string &expression);
	std::vector<size_t> findOperatorPositions(const std::string &expression, char operation);

private:
	OperatorNode *m_rootNode;
	bool m_parsingFailed;
};

#endif
