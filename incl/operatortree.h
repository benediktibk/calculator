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
	double calculateValue() const;

private:
	typedef std::pair<std::string::const_iterator, std::string::const_iterator> bracketPair;

private:
	void parse(std::string expression);
	OperatorNode* parseRecursive(const std::string &expression);
	std::vector<bracketPair> findTopLevelBracketPairs(const std::string &expression);
	std::string::const_iterator findOpeningBracket(const std::string &expression);
	std::string::const_iterator findOpeningBracket(const std::string &expression, const std::string::const_iterator &start);
	std::string::const_iterator findClosingBracket(const std::string &expression, const std::string::const_iterator &openingBracket);
	std::vector<std::string::const_iterator> findMultiplicationsAndDivisionsNotInside(const std::string &expression, const std::vector<bracketPair> &bracketPairs);
	std::vector<std::string::const_iterator> findAdditionsAndSubtractionsNotInside(const std::string &expression, const std::vector<bracketPair> &bracketPairs);
	std::vector<std::string::const_iterator> findOperationsNotInside(const std::vector<std::string::const_iterator> &operations, const std::vector<bracketPair> &bracketPairs);
	std::vector<std::string::const_iterator> findMultiplicationsAndDivisions(const std::string &expression);
	std::vector<std::string::const_iterator> findAdditionsAndSubtractions(const std::string &expression);
	std::vector<std::string::const_iterator> findOperatorPositions(const std::string &expression, const std::vector<char> &operations);

private:
	OperatorNode *m_rootNode;
	bool m_parsingFailed;
};

#endif
