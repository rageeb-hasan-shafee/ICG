
// Generated from C8086Parser.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "C8086ParserVisitor.h"


/**
 * This class provides an empty implementation of C8086ParserVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  C8086ParserBaseVisitor : public C8086ParserVisitor {
public:

  virtual std::any visitStart(C8086Parser::StartContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitProgram(C8086Parser::ProgramContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUnit(C8086Parser::UnitContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunc_declaration(C8086Parser::Func_declarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunc_definition(C8086Parser::Func_definitionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitParameter_list(C8086Parser::Parameter_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCompound_statement(C8086Parser::Compound_statementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVar_declaration(C8086Parser::Var_declarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDeclaration_list_err(C8086Parser::Declaration_list_errContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitType_specifier(C8086Parser::Type_specifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDeclaration_list(C8086Parser::Declaration_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStatements(C8086Parser::StatementsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStatement(C8086Parser::StatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCase_statements(C8086Parser::Case_statementsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCase_statement(C8086Parser::Case_statementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpression_statement(C8086Parser::Expression_statementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVariable(C8086Parser::VariableContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpression(C8086Parser::ExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLogic_expression(C8086Parser::Logic_expressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitRel_expression(C8086Parser::Rel_expressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSimple_expression(C8086Parser::Simple_expressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSimple_expression_err(C8086Parser::Simple_expression_errContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTerm(C8086Parser::TermContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUnary_expression(C8086Parser::Unary_expressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFactor(C8086Parser::FactorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArgument_list(C8086Parser::Argument_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArguments(C8086Parser::ArgumentsContext *ctx) override {
    return visitChildren(ctx);
  }


};

