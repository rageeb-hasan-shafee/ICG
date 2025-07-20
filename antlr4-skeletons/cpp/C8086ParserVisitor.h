
// Generated from C8086Parser.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "C8086Parser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by C8086Parser.
 */
class  C8086ParserVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by C8086Parser.
   */
    virtual std::any visitStart(C8086Parser::StartContext *context) = 0;

    virtual std::any visitProgram(C8086Parser::ProgramContext *context) = 0;

    virtual std::any visitUnit(C8086Parser::UnitContext *context) = 0;

    virtual std::any visitFunc_declaration(C8086Parser::Func_declarationContext *context) = 0;

    virtual std::any visitFunc_definition(C8086Parser::Func_definitionContext *context) = 0;

    virtual std::any visitParameter_list(C8086Parser::Parameter_listContext *context) = 0;

    virtual std::any visitCompound_statement(C8086Parser::Compound_statementContext *context) = 0;

    virtual std::any visitVar_declaration(C8086Parser::Var_declarationContext *context) = 0;

    virtual std::any visitDeclaration_list_err(C8086Parser::Declaration_list_errContext *context) = 0;

    virtual std::any visitType_specifier(C8086Parser::Type_specifierContext *context) = 0;

    virtual std::any visitDeclaration_list(C8086Parser::Declaration_listContext *context) = 0;

    virtual std::any visitStatements(C8086Parser::StatementsContext *context) = 0;

    virtual std::any visitStatement(C8086Parser::StatementContext *context) = 0;

    virtual std::any visitCase_statements(C8086Parser::Case_statementsContext *context) = 0;

    virtual std::any visitCase_statement(C8086Parser::Case_statementContext *context) = 0;

    virtual std::any visitExpression_statement(C8086Parser::Expression_statementContext *context) = 0;

    virtual std::any visitVariable(C8086Parser::VariableContext *context) = 0;

    virtual std::any visitExpression(C8086Parser::ExpressionContext *context) = 0;

    virtual std::any visitLogic_expression(C8086Parser::Logic_expressionContext *context) = 0;

    virtual std::any visitRel_expression(C8086Parser::Rel_expressionContext *context) = 0;

    virtual std::any visitSimple_expression(C8086Parser::Simple_expressionContext *context) = 0;

    virtual std::any visitSimple_expression_err(C8086Parser::Simple_expression_errContext *context) = 0;

    virtual std::any visitTerm(C8086Parser::TermContext *context) = 0;

    virtual std::any visitUnary_expression(C8086Parser::Unary_expressionContext *context) = 0;

    virtual std::any visitFactor(C8086Parser::FactorContext *context) = 0;

    virtual std::any visitArgument_list(C8086Parser::Argument_listContext *context) = 0;

    virtual std::any visitArguments(C8086Parser::ArgumentsContext *context) = 0;


};

