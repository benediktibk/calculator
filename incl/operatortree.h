#ifndef OPERATORTREE_H
#define OPERATORTREE_H

#include <string>
#include <vector>
#include "operatornode.h"

/*!
 * \brief parses and calculates a mathematical expression
 *
 * The operator tree is consctructed from a string, which contains a mathematical expression like 4+7*(4+3). This expression is
 * therefore parsed and can be calculated afterwards with a call to calculateValue.
 * If the parsing failed, because for example a bracket is missing, the flag parsingFailed is set to true.
 * Internally the information is stored in a tree, where the leaves are single values. The nodes above executed the actual calculation.
 * The order in which the expression needs to be calculated is stored through the position in the tree. The closer an operation
 * is to the root node, the later it has to be evaluated. For example 7*(4+3)+4 will result in the following tree:
 *           +
 *         *   4
 *       7  +
 *         4 3
 */
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
	OperatorNode* parseIfAllEnclosedInBrackets(const std::string &expression, const std::vector<OperatorTree::bracketPair> &brackets);
	OperatorNode* parseIfNotEnclosedInBrackets(const std::string &expression, const std::vector<OperatorTree::bracketPair> &brackets);
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
