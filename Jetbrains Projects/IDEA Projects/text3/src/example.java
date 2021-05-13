import java.util.Arrays;
import ilog.concert.IloException;
import ilog.concert.IloLinearNumExpr;
import ilog.concert.IloNumVar;
import ilog.cplex.IloCplex;
public class example {

    public static void main(String[] args) throws IloException {
        IloCplex cplex = new IloCplex();

        // define variables x0 x1 x2
        IloNumVar[] x = new IloNumVar[3];
        x[0] = cplex.numVar(0, 40, "x0");
        x[1] = cplex.numVar(0, Integer.MAX_VALUE, "x1");
        x[2] = cplex.intVar(0, Integer.MAX_VALUE, "x2");

        // objective
//		IloLinearNumExpr obj = cplex.linearNumExpr();
//		obj.addTerm(1, x[0]);
//		obj.addTerm(2, x[1]);
//		obj.addTerm(3, x[2]);
//		cplex.addMaximize(obj);
        double[] c = {1, 2, 3};
        cplex.addMaximize(cplex.scalProd(c, x));

        // constraints
        IloLinearNumExpr c1 = cplex.linearNumExpr();
        c1.addTerm(-1, x[0]);
        c1.addTerm(1, x[1]);
        c1.addTerm(1, x[2]);
        cplex.addLe(c1, 20, "c1");

        IloLinearNumExpr c2 = cplex.linearNumExpr();
        double[] a2 = {1, -3, 1};
        c2.addTerms(a2, x);
        cplex.addLe(c2, 30, "c2");

        // output model
        cplex.exportModel("example_1.lp");

        if (cplex.solve()) {
            System.out.println("Status: " + cplex.getStatus());
            // get optimal objective value
            double objVal = cplex.getObjValue();
            System.out.println("objValue: " + objVal);
            // get optimal solution value
            double[] _x = cplex.getValues(x);
            System.out.println("x = " + Arrays.toString(_x));

            // write solution to file
            cplex.writeSolution("example_1.xml");
        } else {
            System.err.println("Infeasible");
        }
    }
}


