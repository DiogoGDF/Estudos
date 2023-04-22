class TestClass implements TestInterface, TestInterface2
{
    // implementation of square abstract method
    public void square(int a)
    {
        System.out.println(a*a);
    }

    public static void main(String args[])
    {
        TestClass d = new TestClass();
        TestClass d1 = new TestClass();
        d.square(4);

        // default method executed
        d.show();
        TestInterface2.show();
    }
}
