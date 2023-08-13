This directory contains implementations of Factory method design pattern. A brief explanation of this pattern can be found below. 

Factory method is a creational design pattern which solves the problem of creating product objects without specifying their concrete classes.

The Simple factory pattern  describes a class that has one creation method with a large conditional that based on method parameters chooses which product class to instantiate and then return.A simple factory is usually represented by a single method in a single class. Over time, this method might become too big, so you may decide to extract parts of the method to subclasses. Once you do it several times, you might discover that the whole thing turned into the classic factory method pattern.

Here’s an example of simple factory:

class UserFactory {
    public static function create($type) {
        switch ($type) {
            case 'user': return new User();
            case 'customer': return new Customer();
            case 'admin': return new Admin();
            default:
                throw new Exception('Wrong user type passed.');
        }
    }
}

The Factory Method  is a creational design pattern that provides an interface for creating objects but allows subclasses to alter the type of an object that will be created.
If you have a creation method in base class and subclasses that extend it, you might be looking at the factory method.

abstract class Department {
    public abstract function createEmployee($id);

    public function fire($id) {
        $employee = $this->createEmployee($id);
        $employee->paySalary();
        $employee->dismiss();
    }
}

class ITDepartment extends Department {
    public function createEmployee($id) {
        return new Programmer($id);
    }
}

class AccountingDepartment extends Department {
    public function createEmployee($id) {
        return new Accountant($id);
    }
}
 
