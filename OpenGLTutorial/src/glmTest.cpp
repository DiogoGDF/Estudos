    // glm test
    glm::vec4 vec(1.0f, 0.0f, 0.0f, 1.0f);
    // Create a 4x4 transformation matrix
    glm::mat4 trans = glm::mat4(1.0f);

    // Translate the vector by (1(x), 1(y), 0(z))
    // translation
    trans = glm::translate(trans, glm::vec3(1.0f, 1.0f, 0.0f));
    // rotation
    trans = glm::rotate(trans, glm::radians(90.0f), glm::vec3(0.0, 0.0, 1.0)); 
    // scaling
    trans = glm::scale(trans, glm::vec3(0.5, 0.5, 0.5));

    // Multiply the vector by the transformation matrix
    vec = trans * vec;
    // Print the resulting vector
    std::cout << vec.x << vec.y << vec.z << std::endl;
