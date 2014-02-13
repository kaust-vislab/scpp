

set(TEMPLATE_REPO_URL https://github.com/BlueBrain/Template.git)
set(TEMPLATE_DEPENDS bluebrain REQUIRED Boost)
set(TEMPLATE_BOOST_COMPONENTS "unit_test_framework program_options")

if(CI_BUILD_COMMIT)
  set(TEMPLATE_REPO_TAG ${CI_BUILD_COMMIT})
else()
  set(TEMPLATE_REPO_TAG master)
endif()
set(TEMPLATE_FORCE_BUILD ON)
set(TEMPLATE_SOURCE ${CMAKE_SOURCE_DIR})
